*************************************************************MEMORY LOST*************************************************************

When we delete something from our computer, it does not directly gets "deleted" or the computer doesn't instantly "forgets" that memory. 
It "releases" the memory which was allocated to the file, which is now deleted. So, that memory is still there somewhere in the RAM of the computer but it is floating 
and the computer might recognise it just as some garbage values. Note: if ever you want to actually "delete" a file or memory associated with that file from your memory, it is called secure deletion. 

We have a memory card called "card.raw" which had some .jpeg files stored in it (or some pictures, in simple terms), but they got accidently deleted.
The memory which was previously allocated to those files is still there in the memory card but it is lost. 
Hence, we iterate throught the memory card and try to find all the .jpeg files (identified by a unique header) and store each one separately in different files.

The output is 50 different .jpg files recovered from the memory card, from 000.jpg up until 049.jpg.
