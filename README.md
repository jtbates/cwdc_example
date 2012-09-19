# cwdc_example: Building C extensions for Torch in the current working directory 

Simple example for how to write C extensions for your Torch script and install
to the same directory. Nothing outside this directory is touched and Torch's 
regular search path is not polluted.

To build the library issue the command 


    torch-pkg deploy


You can then run the script

    torch run.lua
   
and it will call your C extensions.
