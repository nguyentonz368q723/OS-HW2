# OS-HW2
This is the homework 2 from Nguyen Huu Tam Ton.

**Objective**
- This application is meant to mimic a simple lottery scheduling method. It provides an example of how lottery tickets are allocated to processes and uses a random selection mechanism to choose the next process to execute, therefore presenting an essential method for operating system process scheduling.

**Implementation**
**- The simulation is encapsulated within two primary classes:**

  **+ Process Class:** Represents an individual process, complete with a unique identifier and an array of lottery tickets. It includes functionalities to:
- Add lottery tickets to a process.
- Check for possession of a specific ticket.
- Print the process's details, showcasing its ID and assigned tickets.

**+ Scheduler Class:** Orchestrates the core lottery scheduling algorithm by:
- Facilitating the addition of new processes to the system.
- Allocating lottery tickets to processes.
- Utilizing a random number generator to select a winning ticket and, consequently, the next process to run.

**Usage**
- **Compile the Code:** Utilize a C++ compiler to compile the program. For example, use the command g++ NguyenTon-HW2.cpp -o NguyenTon-HW2 to compile the source file NguyenTon-HW2.cpp into an executable named NguyenTon-HW2.exe.
- **Run the Program:** Execute the compiled program by typing ./HW2 in the terminal. Follow the on-screen prompts to input the necessary information:
- Specify the total number of processes you want to include in the simulation.
- For each process, input the number of tickets it should receive followed by the specific ticket numbers. Ensure each ticket number is unique across all processes.

**Output**
**Upon completion of the input phase, the program will:**
- Display a detailed list of all processes along with their respective lottery tickets.
- Execute the lottery draw to randomly select a winning ticket, announcing the corresponding process as the winner of the scheduling slot.

**Grading Standards**
**1. Functionality:**
   - Appropriately implementing the Process class, which includes managing lottery tickets and a unique identity.
Accurate distribution and handling of lottery tickets for every procedure.
   - The Scheduler class is implemented using the required methods.
   - Appropriate management of the random number generator lottery scheduling technique.
    
**2. Script Submission:**
  - Make sure the script is properly submitted through the appropriate platform.
  - Offer sufficient justification for the implementation decisions through comments or documentation.
