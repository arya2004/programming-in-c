import axios from "axios";
import cheerio from "cheerio";

const query = "mrf_tyres review"; // Updated search query
const url = `https://www.reddit.com/search/?q=${encodeURIComponent(query)}&type=comment&sort=relevance&rdt=48111`;

/**
 * Scrapes comments from Reddit based on a search query.
 */
async function scrape() {
  try {
    const { data } = await axios.get(url);
    const $ = cheerio.load(data);

    const comments = [];

    // Extract comments
    for (let i = 0; i <= 10; i++) {
      const comment = $(`#comment-content-${i}`).text().trim();
      comments.push(comment);
    }

    // Display comments
    for (let i = 0; i <= 10; i++) {
      console.log(`Review ${i + 1}: ${comments[i]}`);
    }
  } catch (error) {
    console.error("An error occurred:", error);
  }
}

scrape();
