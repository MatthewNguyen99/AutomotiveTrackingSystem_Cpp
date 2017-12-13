# AutomotiveTrackingSystem_Cpp
Codes were written in C++ to track Automotive System.  This is OOP (Object Oriented Programming) design.

======================================= Question

QUESTION:

Create a simple object oriented library for tracking automobile maintenance. The system should support at least 
three car types: electric, gas and diesel. 

Each vehicle should have at minimum a make, model, year and odometer reading. Maintenance tasks should include 2-3 
things like oil changes or tire rotations. However, not all maintenance tasks can be applied to all vehicles (an 
electric car won’t need an oil change).

The library or API should be capable of listing, adding, updating and removing entries at runtime. Supply unit tests 
to demonstrate your features.

======================================= Instruction

INSTRUCTION TO SETUP THE PROJECT:

Create this project in Microsoft Visual Studio:
1. File > New Project
2. Templates > VisualC++ > Empty Project
3. Enter name and OK
4. Start coding

INSTRUCTION TO SETUP UNIT TESTING

follow https://blogs.msdn.microsoft.com/vcblog/2017/04/19/cpp-testing-in-visual-studio/
1. Right-click your solution and choose Add > New Project. 
2. Click the Visual C++ category, and choose the Test sub-category.
3. Select Native Unit Test Project, Enter test name if desired.  For now, use name UnitTest1.
3. Click OK.

INSTRUCTION TO ADD TESTS

1. Right click on UnitTest1 > Add > References
2. Click Add New Reference, select project AutomotiveTracking

INSTRUCTION TO RUN TEST:

In the top bar of Microsoft Visual Studio
1. To set up:
  a. Right click UnitTest1 > Properties > Configuration Properties > (select) C/C++ > General > 
     AdditionalIncludeDirectories.
     Scroll down, select edit, add the line "$(SolutionDir)\AutomotiveTrackingSystem"        
  b. (select) Linker > General > AdditionalLibraryDirectories.
     Scroll down, select edit, add the line "$(SolutionDir)\Debug"    
  c. (select) Linker > Input > AddtionalDependencies > 
     Scroll down, select edit, add the line "AutomotiveTrackingSystem.lib"     
     OK 
     Apply > OK     
2. To test
  a. Right click AutomotiveTrackingSystem > Properties > Configuration Properties > General 
  b. Then, change Configuration Type to "Static library (.lib)"
  c. Apply > OK
  
3. To run the code
  a. Right click AutomotiveTrackingSystem > Properties > Configuration Properties > General 
  b. Then, change Configuration Type to "Application (.exe)"
  c. Apply > OK
  
   
      
      
      
      
Test > Run > All Test



