Hi volume!

This C code modifies the volume of an audio file.
**Context**
.WAV files store audio signals as a sequence of samples. The file begins with a 44-byte header, that contains the information about the file, such as the size of the file, nuumber of samples per second, etc. After the header, it contains a sequence of samples, the size of which (in bits) depends on the file. For this project, the sample size is 16-bits (2 bytes). 

The code takes an input.wav file, copies the header seuquence and multiplies the sample sequence by a scaling factor and writes it to an output.wav file. 


