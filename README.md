# routerForSpeedrun
How to use it: <br />
Drag and drop the input file on the program.
The input file contain the steps in the following format : 

stepName nbrOfPrerequisites prerequisite1 prerequisite2 ...

requisites : the steps that need to be completed to complete this step

Example:
You need to go to the boss, but before, you need the sword, and to have the sword, you need a letter and a key. The file should be as follow:
(The order doesn't matter)

sword 2 key letter<br/>
boss 1 sword<br/>
letter 0<br/>
key 0<br/>



Route:

letter
key
sword
boss
