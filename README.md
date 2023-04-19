# CheckPoint

![CheckPoint logo](https://github.com/seven707070/CheckPoint/blob/main/check.png?raw=true)

A command line program for backing up the working directory to a set destination, the default is the desktop. When using it on a folder named 'Example' for the first time it'll create on the desktop a folder named 'Example_CheckPoint'. Inside it, it'll create a folder named 'Example_0' and copy the contents of 'Example' to it, next time you use it, it'll back up your working directory to 'Example_1' and so on.
  Copy 'save.exe' and 'save.bat' to a folder on your computer and add its path to the "Path" environment variable to be able to use the program in any directory by typing 'save' in the command line. You can change the alias to call it by changing the 'save.bat' file's name. For example you can call the program by typing 's' if you rename 'save.bat' to 's.bat'. You should change the path in the 'save.bat' to match the path of 'save.exe' on your computer. You can optionally provide a message when calling the program (example: save This is a message) the message you provide will be included in the back up folder in a file named 'CheckPoint.txt'. 
    I provided a variation named 'save_README.c'. In this variant, the message you provide is saved in the top of the 'README.txt' instead of creating 'CheckPoint.txt', if no 'README.txt' file exists, it'll create one.

# Tutorial


https://user-images.githubusercontent.com/131197086/233012542-1d9c496d-7538-4f82-b439-4f6dbb1cc737.mp4


# Contact

s24949897@gmail.com
