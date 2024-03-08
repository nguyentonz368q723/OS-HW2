/*
Name: Nguyen Huu Tam Ton
Class: CS 540
HW2: 03/07/2024

Objective: The task entails developing an algorithm for lottery scheduling,
in which processes are given lottery tickets, and the scheduler
chooses a ticket at random to decide which process to run next.
*/

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std; // I'm opting to use the standard namespace to simplify the code.

class Process {
private:
    int id; // I keep the unique identifier private for encapsulation.
    vector<int> tickets; // Here's where I store each process's lottery tickets.

public:
    Process(int id) : id(id) {} // I initialize the process with a unique ID.

    int getId() const { // I added a getter for the ID to safely access it from outside the class.
        return id;
    }

    void addTicket(int ticket) { // This method allows me to add a lottery ticket to the process.
        tickets.push_back(ticket);
    }

    bool hasTicket(int ticket) const { // Here, I check if the process has a specific ticket.
        return find(tickets.begin(), tickets.end(), ticket) != tickets.end();
    }

    void printTickets() const { // I use this to print all tickets of a process for debugging.
        cout << "Process " << id << " has tickets: ";
        for (int t : tickets) {
            cout << t << " ";
        }
        cout << endl;
    }

    void announceWin() const { // If a process wins, I announce it here.
        cout << "Process " << id << " wins the lottery!" << endl;
    }
};

class Scheduler {
private:
    vector<Process> processes; // I store all processes here.
    vector<int> allTickets; // And all the tickets to keep track of them.

public:
    void addProcess(const Process& process) { // This allows me to add processes to the scheduler.
        processes.push_back(process);
    }

    bool allocateTicket(int processId, int ticket) { // Here, I allocate tickets to processes, ensuring no duplicates.
        if (find(allTickets.begin(), allTickets.end(), ticket) != allTickets.end()) {
            cout << "Ticket " << ticket << " is already allocated. Please choose another." << endl;
            return false;
        } else {
            allTickets.push_back(ticket);
            for (Process& process : processes) {
                if (process.getId() == processId) { // I use getId() to safely access the process ID.
                    process.addTicket(ticket);
                    break;
                }
            }
            return true;
        }
    }

    void displayProcesses() const { // I display all processes with their tickets for clarity.
        for (const Process& process : processes) {
            process.printTickets();
        }
    }

    void drawWinner() const { // Finally, I draw the winner by selecting a random ticket.
        if (allTickets.empty()) {
            cout << "No tickets have been allocated." << endl;
            return;
        }
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, allTickets.size() - 1);

        int winningTicket = allTickets[dis(gen)];
        cout << "Drawing the winning ticket... " << winningTicket << endl;

        for (const Process& process : processes) {
            if (process.hasTicket(winningTicket)) {
                process.announceWin();
                break;
            }
        }
    }
};

int main() {
    Scheduler scheduler; // I start by creating the scheduler.
    int numProcesses;
    cout << "Enter the number of processes: ";
    cin >> numProcesses; // I ask the user how many processes they want to create.

    for (int i = 0; i < numProcesses; ++i) { // For each process, I collect their tickets.
        Process process(i + 1);
        int numTickets;
        cout << "Enter the number of tickets for Process " << (i + 1) << ": ";
        cin >> numTickets;

        for (int j = 0; j < numTickets; ++j) {
            int ticket;
            cout << "Enter ticket number: ";
            cin >> ticket;
            scheduler.allocateTicket(i + 1, ticket); // I allocate each ticket to the process.
        }

        scheduler.addProcess(process); // Then, I add the fully setup process to the scheduler.
    }

    scheduler.displayProcesses(); // Before the draw, I display all processes for verification.
    scheduler.drawWinner(); // Finally, I draw and announce the winning ticket and process.

    return 0;
}
