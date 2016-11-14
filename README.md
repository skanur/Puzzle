# CILK Project - Puzzle

## Getting Started

1. The starting point of this project is the github repository you got from the instructions from Moodle. Its in the form `Puzzle-yourgithubid`. For instance, my project would be called `Puzzle-skanur`.

2. Open a terminal and clone the project into your local machine using `git clone`. Navigate into the project directory. I would clone my project as below. Your repository link will be different.
    ```bash
    git clone https://github.com/ESLab/Puzzle-skanur.git
    cd Puzzle-skanur
    ```

4. Download the `Small Picture Set` from course webpage. Unzip it in your project directory. On my computer this creates a folder `small_picture_set` that has all the pictures I want to compare with.

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

## Using VTune-Amplifier
