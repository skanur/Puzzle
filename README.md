# CILK Project - Puzzle

## Working in teams

If you are new to using git for collaborative projects, go through this [5 minute read](https://guides.github.com/introduction/flow/) to understand how to use github in team. 

More detailed guide on [git](https://www.codeschool.com/courses/git-real).

*Tip:* If everyone pushes to master all the time, you'll soon run into serious problems with your repository. Instead assign one team member in-charge of merging the code to the master branch and tagging the versions according to the milestones. The rest of the members can submit their features through pull-requests.

## Getting Started

1. Clone your project and navigate to the project directory. Download `Small Picture Set` from Moodle and unzip in this directory.

5. You can work on the project either using an IDE or using command line. The next setup instructions describe working with KDevelop IDE. If you know how to work with CMake projects, you can skip setting up IDE and work from the terminal and your favorite text editor.

6. Open another terminal tab or window. Open KDevelop as
    ```bash
    use parallelstudio
    export CC=icc CXX=icpc
    kdevelop &
    ```

7. To create a project click `Project->Open/Import Project`. A dialogue opens. Open your project directory from the browse window, select `CMakeLists.txt` and click `Next`. The dialogue window gives the following info - Name: Puzzle, Build System: CMake Project Manager. Click `Finish`. In the configuration window, choose the defaults and click `OK`.

8. Click on `Build` button to build the entire project. It creates an executable for the C++ project `puzzlediff_cpp`. 

9. Let's create an executable configuration for `puzzlediff_cpp`. Click `Run->Configure Launches`. A dialogue opens. Right click on `New Application Launcher` and rename it to `puzzlediff_cpp_debug`. Under `Project Target`, choose `Puzzle/puzzlediff_cpp/puzzlediff_cpp`. Enter the arguments for the executable `small_picture_set/0_5mpix_boat.jpg small_picture_set/0_5mpix_tree.jpg`. You can change this to any picture of your choice. Choose the current project directory as your `Working Directory`. Under Dependencies, choose the action `Build`. Click `Apply` and `OK`. 

10. You can now click on `Execute` to run this configuration. Verify if the output from your console matches the value given in the document `Vector distances for all pictures in small picture set` on Moodle.

12. You can change the arguments to your executables at any time by clicking `Run->Configure Launches` and editing your launch configuration.

13. Every time you need to work on a different machine, you have to repeat the steps above.

13. **WARNING**: This repo will be deleted after the exercise assessment without any prior notice. If you want a copy of it, fork it **privately**. Forking it publicly will automatically void your entire team!

## Profiling the application

Many tools are available for profiling sequential application and this readme will cover profiling using Valgrind/Callgrind. You can always use a different tool to achieve the same goal. Profiling the application gives us an opportunity to note the areas that benefit from optimizations. In addition you can also generate Callgraphs that indicate the program flow.

To profile an application, first build the application using the above steps. If you have followed the above steps, the C++ executable is present in the folder `build/puzzlediff_cpp/`. Profiling is carried out in two steps.

1. Open a terminal. This example assumes that you have your picture folder in the project folder.

    ```bash
    use parallelstudio
    export CC=icc CXX=icpc
    cd build
    cmake .. && make
    valgrind --tool=callgrind -v puzzlediff_cpp/puzzlediff_cpp ../small_picture_set/0_5mpix_car.jpg ../small_picture_set/20mpix_car.jpg
    ```

2. This will create a file `callgrind.out.$$$$`, where `$$$$` is some random number. Now open `kcachegrind` using this file

    ```bash
    kcachegrind callgrind.out.$$$$
    ```

The window that opens already has a side pane with function calls that took maximum amount of relative execution time, a center pane with tabs listing Callers, Source Code etc., and a bottom pane with Callgraphs for different functions. You can find more information about Kcachegrind [here](http://kcachegrind.sourceforge.net/html/Screenshots.html). Note that everytime you run step 1, you create a different file `callgrind.out.$$$$$`. So make sure you are supplying the right file in step 2.

## Input and Output Specifications

The final application should have the input and output specs detailed below. You can use the `listdir.cpp` in the folder puzzlediff_cpp to read the folder contents.

### Input
`command file directory` where
*command* The name of the application

*file* The file name of the reference picture. The application should try to find pictures similar to the reference picture

*directory* The name of the directory to be searched for pictures similar to the reference picture. The application should search all the files included in this directory. Support for recursive searching in the sub-folders are NOT necessary. All files in the directory should be read, not only those with a certain file extension!

Examples:
```bash
puzzlediff_cpp small_picture_set/0_5mpix_boat.jpg small_picture_set
```

### Output

The application should produce as its output a list of the file names of the **10 most similar pictures found, as well as a list of pictures found to be identical or close resemblance to the reference picture**. The vector distance to the reference picture vector should be available in the output (and used to sort the lists). Pictures with a vector distances **shorter than or equal to 0.12** (to the reference image) should be placed in the identical/close resemblance list, sorted according to vector distance. Vector distances **longer than 0.12** are placed in the list of similar images and sorted according to vector distance. 

**Don't list copies of pictures that are already in the top 10 list in either of the lists**

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

## Developing on your laptop

We will use a VirtualBox image that consists of all the necessary tools for compiling the project. The image provided is only for convenience and does not replace running your project on the workstations of the lab.

### Requirements

Your machine should have a minimum of 2 GB of memory and a dual core CPU that supports hyper-threading and virtualisation. It is recommended to have a 4 GB of memory and a 4 core CPU. It is also recommended to have an Ethernet connection for faster installation.

Install the following on your machine.

1. [Vagrant](https://www.vagrantup.com/downloads.html)

2. [VirtualBox](https://www.virtualbox.org/wiki/Downloads).

### Getting started

1. Once you have installed Vagrant and Virtualbox according to your platform, open a terminal (`cmd` in Windows) and navigate to your project directory.

2. Perform the following one time setup. This will take sometime based on your internet connection. Its is recommended to use an Ethernet connection for faster install.

    ```bash
    vagrant init skanur/manycore
    vagrant plugin install vagrant-vbguest
    ```

### Development

1. Once you have installed the box, you can start the Virtualbox with following commands. On Windows, you might need to use a 3rd party client to SSH. The username and password for the container is `vagrant`.

    ```bash
    vagrant up
    vagrant ssh
    cd /vagrant
    ```

2. Once you are in `/vagrant`, to compile, run

    ```bash
    ./compile_on_laptop.sh
    ```

3. To shutdown the Virtualbox, run

    ```bash
    exit
    vagrant halt
    ```

4. You can then begin development again starting from step 1.
