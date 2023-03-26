# Process-Scheduling-Simulator-cpp
Implement the Process Scheduling Simulator using Multilevel Feedback Queues(linked list based implementation with the following scheduling algorithms using C++ )

Objective:
Implement the Process Scheduling Simulator using Multilevel Feedback Queues(linked list
based implementation with the following scheduling algorithms using C++ )
FCFS (First Come First Serve)
SJF (Shortest Job First)
As we know different processes are running in our operating system. The process at first is
present in ready queue (This queue keeps a set of all processes residing in main memory, ready
and waiting to execute). Some of these processes are foreground processes and some are
background processes. These two classes have different scheduling needs. Each process has
process id, type , arrival time and set of operations it has to perform. These processes need to be
scheduled to complete their job. For scheduling purposes multi-level queue is used. Multi-level
queue uses some scheduling algorithms to schedule these processes, These multi-level queue are
order from high to low priority queue. Each queue has its own scheduling algorithm and queue
id (you can find more about multi-level queue on this link). The details of some scheduling
algorithms are given below.
 FCFS (First Come First Serve): One of the most simplest process scheduling algorithm, it
basically run jobs in the order they arrive. It is non-preemptive (keeps CPU until done or
blocked when have input/output operations.). You can find more about FCFS on this link.
 SJF (Shortest Job First): This scheduling algorithm will look into the CPU burst time and

run whatever job has smallest next CPU burst time. SJF can be preemptive as well as non-
preemptive. In this assignment you are required to implement the preemptive version

(possible to get the CPU back from a process, even if the process has not completed its
execution) of SJF. More about SJF can be found in the given link.
For this assignment, you are required to implement a process scheduler simulator that takes as
input the system configuration file (.xml file ) that gives information regarding the configuration
information and processes information to simulate Multilevel Feedback Queues. Example of
configuration file is given below:

CPU configuration and the processes must be in a file as follows:

<AssignmentInput>
<QueueSet>
<SetName>Background Queues</SetName>
<UpgradePolicy>time, priority</UpgradePolicy>
<DowngradePolicy> time, priority </DowngradePolicy>
<QAllocPolicy>FirstQueueNumber</QAllocPolicy>
<Queue>
<SchedulingPolicy> FCFS/SJF</SchedulingPolicy>
</Queue>
<Queue>
<SchedulingPolicy> SJF/FCFS</SchedulingPolicy>
</Queue>
...
</QueueSet>
<Configuration>
<Processes number=No._of_Processes>
<Process ID=P1>
<ArrivalTime>time_in_seconds</ArrivalTime>
<Priority>High/Medium/Low</Priority>
<Type>CPU_Bound/IO_Bound</Type>
<code>set of instructions, see below for example</code>
</Process>
<Process ID=P2>
<ArrivalTime>time_in_seconds</ArrivalTime>
<Priority>High/Medium/Low</Priority>
<Type>CPU_Bound/IO_Bound</Type>
<code>set of instructions, see below for example</code>
</Process>
...
...
<Process ID=Pn>
<ArrivalTime>time_in_seconds</ArrivalTime>
<Priority>High/Medium/Low</Priority>
<Type>CPU_Bound/IO_Bound</Type>
<code>set of instructions, see below for example</code>
</Process>
</Processes>
</Configuration
</ AssignmentInput >

The <code> element:
The data between the <code> and </code> elements of the input file specify a set of instructions
associated with each process. There are three types of instructions, READ, WRITE and
COMPUTE. These instructions represent CPU computations and read/write data to devices and
memory. Different devices are represented by a set of keywords as below:
DISK: This keyword represents the hard disk.
SCREEN: represents the monitor.
PRINTER: represents the printer.
KEYBOARD: represents the keyboard.
MEMORY: represents the main memory.
FILE: represents an ordinary file
Read and Write instructions to the devices are blocking and would cause the calling
process to wait for some time.
Read and Write instructions to memory are non-blocking and so as the COMPUTE
instruction.
We can also assume that each non-blocking instruction takes an equal time and each
blocking instruction takes a minimum of 3 non-blocking instructions.

Example of input file is given below

Example of the input file:
<AssignmentInput>
<QueueSet>
<SetName>Background Queues</SetName>
<UpgradePolicy>time</UpgradePolicy>
<DowngradePolicy> time </DowngradePolicy>
<QAllocPolicy>2</QAllocPolicy>
<Queue 1>
<SchedulingPolicy> FCFS </SchedulingPolicy>
</Queue 1>
<Queue 2>
<SchedulingPolicy> SJF</SchedulingPolicy>
</Queue 2>
....
</QueueSet>
<Configuration>
<Processes number=2 >
<Process ID=P1>
<ArrivalTime>0</ArrivalTime>
<Type>IO_Bound</Type>
<code>
WRITE SCREEN
READ KEYBOARD
COMPUTE
READ MEMORY
COMPUTE
WRITEMEMORY
WRITE PRINTER
</code>
</Process>
<Process ID=P2>
<ArrivalTime>3</ArrivalTime>
<Type>CPU_Bound</Type>
<code>
WRITE MEMORY
READ MEMORY
COMPUTE
</code>
</Process>
...............
</Processes>
</Configuration>
</AssignmentInput>

1. In the input file above there is one queue set of background processes.
2. Two queues within that queue set, one with scheduling policy FCFS and second with
scheduling policy SJF.
3. In configuration we have two processes, once the first process is blocked because of
WRITE instruction, the second process gets the CPU and once the second process
executes three non-blocking instructions, the first process unblocks.
4. Process 1 has a blocking instruction and it would thus block. If there is some other
process waiting in the ready queue it would get the CPU and once the sufficient time
has been elapsed (equivalent to 3 non- blocking instructions) the blocked process would
unblock. Indeed this time starts when the blocked process gets the device it is waiting
for and is not stuck in some device queue (processes that are blocked due to
unavailability of an I/O device constitute this queue).

Expected output:
In addition to the instructions discussed above, there is one special instruction called
breakpoint. This instruction can appear anywhere in the input file and would require to
suspend processes execution (simulation) so that the processes and queues state can be
viewed. For instance in the example above, if we add a <breakpoint/> element after the first
instruction of process 1, it should allow the user to examine the contents of different queues
and later continue from the breakpoint. In general, at any stage (once a breakpoint is
encountered or all the processes terminate) it should be possible to view the following:
• Processes Status
• The code for each process that has been executed
• The contents of different queues, including ready queue and device queues for each
device. Each device queue is implemented as a FIFO queue
• The order of execution for each process
The optimization criterion for each scheduling approach including turn around, waiting and
completion times for each process
Note: The above given input file is just an example file, at the time of demo there can be multiple
processes so your program should show the scheduling simulation of all processes present in the
input file.
