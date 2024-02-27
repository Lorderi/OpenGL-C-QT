An application has been created to visualize a wireframe model in three-dimensional space using the following conditions:

- The program is implemented in the C language standard C11 using the gcc compiler, as well as additional libraries and QT modules.
- The developed application follows the principles of structured programming and Google's coding style.
- Provided module coverage with unit tests, model loading interrupts, and affine envelopes.
The functionality of the program includes:
   - Ability to load a wireframe model from an obj shape file (only a list of vertices and accesses is supported).
   - The ability to move the model along the X, Y, Z axes at a specified distance.
   - The ability to rotate the model at a given angle relative to the X, Y, Z axis.
   - Possibility of scaling the model by a given value.
   - A button for selecting a file model and a field for displaying its name have been implemented.
   - The wireframe model visualization area has been created.
   - Controls have been introduced to move, rotate and scale the model.
   - Added information about the loaded model, such as file name, number of vertices and edges.
The program processes and views models with different levels of vertices without dependence on the interface (up to 100, 1000, 10,000, 100,000, 1,000,000 vertices).

Additional functions:

- Implemented selection of projection type (parallel and central).
- Added settings for edge type (flat, dotted), edge color and thickness, appearance, vertex color and size.
- Implemented choice of flashlight color.
- Saving of settings between program launches is ensured.
- The ability to save images to a file in bmp and jpeg formats has been implemented.
- Added the function of creating GIF animation of affine transformations of a loaded object upon request (640x480, 10fps, 5s).