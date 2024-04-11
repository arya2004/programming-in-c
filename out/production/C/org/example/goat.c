#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a basic XML node
struct XmlNode {
    char *tag;              // Tag name
    char *content;          // Text content within the node
    struct XmlNode *parent; // Pointer to the parent node
    struct XmlNode **children; // Array of pointers to child nodes
    size_t numChildren;     // Number of children
};

// Function to create a new XML node
struct XmlNode* createXmlNode(const char *tag, const char *content) {
    struct XmlNode *node = (struct XmlNode*)malloc(sizeof(struct XmlNode));
    if (node == NULL) {
        perror("Failed to allocate memory for XML node");
        exit(1);
    }
    node->tag = strdup(tag);
    node->content = strdup(content);
    node->parent = NULL;
    node->children = NULL;
    node->numChildren = 0;
    return node;
}

// Function to add a child node
void addChildNode(struct XmlNode *parent, struct XmlNode *child) {
    parent->children = (struct XmlNode**)realloc(parent->children, (parent->numChildren + 1) * sizeof(struct XmlNode*));
    if (parent->children == NULL) {
        perror("Failed to allocate memory for child nodes");
        exit(1);
    }
    parent->children[parent->numChildren] = child;
    child->parent = parent;
    parent->numChildren++;
}

// Function to parse XML and create the tree representation
struct XmlNode* parseXml(const char *xml) {
    struct XmlNode *root = NULL;
    struct XmlNode *current = NULL;
    const char *pos = xml;
    char tag[256];
    char content[1024];
    size_t contentIndex = 0;
    int insideTag = 0;
    int insideClosingTag = 0;

    while (*pos != '\0') {
        if (*pos == '<') {
            const char *tagStart = pos + 1;
            const char *tagEnd = strchr(tagStart, '>');
            if (tagEnd) {
                int tagLength = tagEnd - tagStart;

                // Check for closing tag
                if (tagStart[0] == '/') {
                    insideClosingTag = 1;
                    tagStart++; // Move past '/'
                } else {
                    insideTag = 1;
                    insideClosingTag = 0;
                }

                if (tagLength > 0) {
                    strncpy(tag, tagStart, tagLength);
                    tag[tagLength] = '\0';

                    if (insideTag) {
                        if (insideClosingTag) {
                            if (current != NULL && strcmp(tag, current->tag) == 0) {
                                // Closing tag matches the current node
                                current = current->parent;
                            }
                        } else {
                            // Opening tag
                            struct XmlNode *newNode = createXmlNode(tag, "");
                            if (root == NULL) {
                                root = newNode;
                            } else if (current != NULL) {
                                addChildNode(current, newNode);
                            }
                            current = newNode;
                        }
                    } else {
                        // Text content within a tag
                        strncpy(content, tag, tagLength);
                        contentIndex = tagLength;
                    }

                    insideTag = 0;
                }

                pos = tagEnd + 1;
            } else {
                pos++;
            }
        } else if (*pos == '>') {
            pos++;
        } else {
            // Text content
            if (current != NULL && !insideTag) {
                if (contentIndex < sizeof(content) - 1) {
                    content[contentIndex] = *pos;
                    contentIndex++;
                }
            }
            pos++;
        }
    }

    return root;
}

// Function to recursively print the XML tree with indentation
void printXmlTree(struct XmlNode *node, int depth) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    printf("<%s>%s\n", node->tag, node->content);

    for (size_t i = 0; i < node->numChildren; i++) {
        printXmlTree(node->children[i], depth + 1);
    }
}

int main() {
    // Sample XML string
    const char *xmlString = "<root><element1>Content1</element1><element2>Content2</element2><element1>Content1</element1><element2>Content2</element2><element1>Content1</element1><element2>Content2</element2></root>";

    // Parse the XML string and create the tree representation
    struct XmlNode *xmlRoot = parseXml(xmlString);

    // Print the XML tree
    printf("XML structure:\n");
    printXmlTree(xmlRoot, 0);

    // TODO: Clean up the memory (free the nodes and their arrays)

    return 0;
}
