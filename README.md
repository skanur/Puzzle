# CILK Project - Puzzle

## Working in teams

If you are new to using git for collaborative projects, go through this [5 minute read](https://guides.github.com/introduction/flow/) to understand how to use github in team. 

More detailed guide on [git](https://www.codeschool.com/courses/git-real).

*Tip:* Assign one team member in-charge of merging the code to the master branch and tagging the versions according to the milestones. 

## Getting Started

1. Clone your project and navigate to the project directory. Download `Small Picture Set` from Moodle and unzip in this directory.

5. You can work on the project either using an IDE or using command line. The next setup instructions describe working with KDevelop IDE. If you know how to work with CMake projects, you can skip setting up IDE and work from the terminal and your favorite text editor.

6. Open another terminal tab or window. Open KDevelop as
    ```bash
    use parallelstudio
    kdevelop &
    ```

7. To create a project click `Project->Open/Import Project`. A dialogue opens. Open your project directory from the browse window, select `CMakeLists.txt` and click `Next`. The dialogue window gives the following info - Name: Puzzle, Build System: CMake Project Manager. Click `Finish`. In the configuration window, choose the defaults and click `OK`.

8. Click on `Build` button to build the entire project. It creates two executables, one for C project `puzzlediff` and another for the C++ project `puzzlediff_cpp`. 

9. Let's create an executable configuration for `puzzlediff`. Click `Run->Configure Launches`. A dialogue opens. Right click on `New Application Launcher` and rename it to `puzzlediff_debug`. Under `Project Target`, choose `Puzzle/puzzlediff/puzzlediff`. Enter the arguments for the executable `small_picture_set/0_5mpix_boat.jpg small_picture_set/0_5mpix_tree.jpg`. You can change this to any picture of your choice. Choose the current project directory as your `Working Directory`. Under Dependencies, choose the action `Build`. Click `Apply` and `OK`. 

10. You can now click on `Execute` to run this configuration. Verify if the output from your console matches the value given in the document `Vector distances for all pictures in small picture set` on Moodle.

11. Similarly, you can create another executable configuration for `puzzlediff_cpp`. Just choose to add new `Application` after you click `Run-Configure Launches`. You can switch between any executable configurations by selecting `Run->Current Launch Configuration`. 

12. You can change the arguments to your executables at any time by clicking `Run->Configure Launches` and editing your launch configuration.

13. Every time you need to work on a different machine, you have to repeat the steps above.

13. **WARNING**: This repo will be deleted after the exercise assessment without any prior notice. If you want a copy of it, fork it **privately**. Forking it publicly will automatically void your entire team!

## Using VTune-Amplifier

## Input and Output Specifications

The final application should have the following input and output specs

### Input
`command file directory` where
*command* The name of the application

*file* The file name of the reference picture. The application should try to find pictures similar to the reference picture

*directory* The name of the directory to be searched for pictures similar to the reference picture. The application should search all the files included in this directory. Support for recursive searching in the sub-folders are NOT necessary. All files in the directory should be read, not only those with a certain file extension!

Examples:
```bash
puzzlediff small_picture_set/0_5mpix_boat.jpg small_picture_set

puzzlediff_cpp some_ref_pic.png ~/large_picture_set
```

### Output

The application should produce as its output a list of the file names of the **10 most similar pictures found, as well as a list of at most 10 pictures found to be identical or close resemblance to the reference picture**. The vector distance to the reference picture vector should be available in the output (and used to sort the lists). Pictures with a vector distances **shorter than or equal to 0.12** (to the reference image) should be placed in the identical/close resemblance list, sorted according to vector distance. Vector distances **longer than 0.12** are placed in the list of similar images and sorted according to vector distance. 

**Don't list copies of pictures that are already in the top 10 list in either of the top 10 lists**

Examples:

```bash
*** Pictures found to be identical/close resemblance to
myrefpicture.jpg ***
0.00 a_copy.jpg
0.05 imgA.jpg
0.06 imgB.jpg
0.12 imgC.png

*** Pictures found to be similar to myrefpicture.jpg ***
0.125 img4.jpg
0.143 img7.jpg
0.200 img1.jpg
0.240 img5.jpg
0.300 img8.png
0.360 img3.jpg
0.652 img11.jpg
0.880 img2.png
0.880 img4.png 
0.920 img9.png
```

## Milestones and tagging

The project requires delivering code at three different points of time. For more information refer to the document *Project Schedule and Milestones* on Moodle. Here is some information related to code part:

1. Milestone 2: Deliver the working sequential code according to the input/output specs for this milestone by first tagging it as `git tag -a mile2 -m "Milestone 2"` and pushing `git push --follow-tags origin master`. Deadline **Thursday 1.12, 23:55**

2. Milestone 3: Deliver the working parallel code according to the input/output specs for this milestone by first tagging it as `git tag -a mile3 - m "Milestone 3"` and pushing `git push --follow-tags origin master` . Deadline **Thursday 7.12 23:55**

3. Final code: Deliver the final working code that was used on Xeon machine by first tagging it as `git tag -a final` and pushing `git push --follow-tags origin master`. 
