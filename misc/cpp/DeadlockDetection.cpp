#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * @brief Implements the Safety Algorithm to detect deadlock.
 * 
 * @param AllocatedResources Matrix representing resources allocated to processes.
 * @param MaxResource Matrix representing maximum resources required by processes.
 * @param NeedResources Matrix representing needed resources by processes.
 * @param AvailableResources Vector representing available resources.
 * @param Finished Vector representing finished processes.
 * @param SafeSequence Vector to store the safe sequence of processes.
 * @param noOfProcesses Number of processes.
 * @param noOfResources Number of resources.
 * @return true if system is in a safe state, false if in deadlock.
 */
bool SafetyAlgorithm(vector<vector<int>> AllocatedResources, vector<vector<int>> MaxResource, vector<vector<int>> NeedResources, vector<int> AvailableResources, vector<bool> &Finished, vector<int> &SafeSequence, const int noOfProcesses, const int noOfResources)
{
    int safeSequenceCounter = 0;

    for (int i = 0; i < noOfProcesses; i++)
    {
        for (int j = 0; j < noOfProcesses; j++)
        {
            if (!Finished[j])
            {
                bool isGoodToGo = true;
                for (int r = 0; r < noOfResources; r++)
                {
                    if (NeedResources[j][r] > AvailableResources[r])
                    {
                        isGoodToGo = false;
                        break;
                    }
                }

                if (isGoodToGo)
                {
                    SafeSequence[safeSequenceCounter++] = j;

                    for (int r = 0; r < noOfResources; r++)
                    {
                        AvailableResources[r] += AllocatedResources[j][r];
                        Finished[j] = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i < noOfProcesses; i++)
        if (SafeSequence[i] == -1)
            return false;
    return true;
}

/**
 * @brief Removes processes in deadlock and checks if system is still in deadlock.
 * 
 * @param AllocatedResources Matrix representing resources allocated to processes.
 * @param MaxResource Matrix representing maximum resources required by processes.
 * @param AvailableResources Vector representing available resources.
 * @param Finished Vector representing finished processes.
 * @param SafeSequence Vector to store the safe sequence of processes.
 * @param noOfProcesses Number of processes.
 * @param noOfResources Number of resources.
 * @param InDeadlock Vector of process IDs in deadlock.
 */
void RemoveAndCheckDeadlock(vector<vector<int>> AllocatedResources, vector<vector<int>> MaxResource, vector<int> AvailableResources, vector<bool> &Finished, vector<int> &SafeSequence, const int noOfProcesses, const int noOfResources, vector<int> InDeadlock)
{
    cout << "Processes in Deadlock : ";
    for (auto i : InDeadlock)
    {
        cout << i << ",";
    }
    cout << endl;

    for (int i = 0; i < InDeadlock.size(); i++)
    {
        int PID = InDeadlock[i];
        for (int j = 0; j < noOfResources; j++)
        {
            AvailableResources[j] += AllocatedResources[PID][j];
            AllocatedResources[PID][j] = 0;
            MaxResource[PID][j] = 0;
        }

        vector<vector<int>> NeedResources(noOfProcesses, vector<int>(noOfResources));
        for (int k = 0; k < noOfProcesses; k++)
            for (int j = 0; j < noOfResources; j++)
                NeedResources[k][j] = MaxResource[k][j] - AllocatedResources[k][j];

        vector<bool> Finished(noOfProcesses, false);

        bool notInDeadlock = SafetyAlgorithm(AllocatedResources, MaxResource, NeedResources, AvailableResources, Finished, SafeSequence, noOfProcesses, noOfResources);
        
        if (notInDeadlock)
        {
            cout << "Deadlock Recovery: Remove Process IDs : ";
            for (int j = 0; j <= i; j++)
            {
                cout << InDeadlock[j] << ", ";
            }
            cout << endl;
            return;
        }
    }
    cout << "Deadlock Recovery: Remove Process IDs : ";
    for (int j = 0; j <= InDeadlock.size(); j++)
    {
        cout << InDeadlock[j] << ", ";
    }
    cout << endl;
    return;
}

int main()
{
    int noOfProcesses, noOfResources;
    cout << "\nNo of Processes and Resources: ";
    cin >> noOfProcesses >> noOfResources;

    vector<vector<int>> AllocatedResources(noOfProcesses, vector<int>(noOfResources));
    vector<vector<int>> MaxResource(noOfProcesses, vector<int>(noOfResources));
    vector<int> AvailableResources(noOfResources);
    vector<vector<int>> NeedResources(noOfProcesses, vector<int>(noOfResources));

    for (int i = 0; i < noOfProcesses; i++)
    {
        cout << "\nAllocated Resources to " << i << ": ";
        for (int j = 0; j < noOfResources; j++)
        {
            cin >> AllocatedResources[i][j];
        }
    }

    for (int i = 0; i < noOfProcesses; i++)
    {
        cout << "\nMax Resources to " << i << ": ";
        for (int j = 0; j < noOfResources; j++)
        {
            cin >> MaxResource[i][j];
        }
    }

    cout << "\nAvailable Resource: ";
    for (int i = 0; i < noOfResources; i++)
    {
        cin >> AvailableResources[i];
    }

    for (int i = 0; i < noOfProcesses; i++)
        for (int j = 0; j < noOfResources; j++)
            NeedResources[i][j] = MaxResource[i][j] - AllocatedResources[i][j];

    vector<int> SafeSequence(noOfProcesses, -1);
    vector<bool> Finished(noOfProcesses, false);

    bool isSafe = SafetyAlgorithm(AllocatedResources, MaxResource, NeedResources, AvailableResources, Finished, SafeSequence, noOfProcesses, noOfResources);

    vector<int> InDeadlock;

    if (isSafe)
    {
        cout << "\nSystem is not in Deadlock.\n" << endl;
        return 0;
    }

    for (int i = 0; i < noOfProcesses; i++)
    {
        if (!Finished[i])
        {
            InDeadlock.push_back(i);
        }
        else
        {
            int PID = i;
            for (int j = 0; j < noOfResources; j++)
            {
                AvailableResources[j] += AllocatedResources[PID][j];
                AllocatedResources[PID][j] = 0;
                MaxResource[PID][j] = 0;
            }
        }
    }

    RemoveAndCheckDeadlock(AllocatedResources, MaxResource, AvailableResources, Finished, SafeSequence, noOfProcesses, noOfResources, InDeadlock);
    return 0;
}
