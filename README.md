# routerForSpeedrun
How to use it: \
Bring the name/path to the input file as the first argument or drag and drop the input file on the program. \
By default, the output file is named route.txt, make sure it is not the name of an existing file that you don't want overwrite. You can name the output file yourself by giving its name as the second argument.\
The input file contain the steps in the following format : 

stepName1 nbrOfPrerequisites prerequisite1 prerequisite2 ... \
stepName2 nbrOfPrerequisites prerequisite1 prerequisite2 ... \
stepName3 nbrOfPrerequisites prerequisite1 prerequisite2 ... \
...

Prerequisites : the steps that need to be completed before completing this step.

# Example:
To defeat the boss, you must have a sword. But to obtain that sword, you need a letter and a key. \
The file should be as follow: (The order doesn't matter)

sword 2 key letter \
boss 1 sword \
letter 0 \
key 0



The corresponding route will be:

letter \
key \
sword \
boss
