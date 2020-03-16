# Description
algorithms for dilation, erosion and opening on any structuring element

# Usage

The images that the program inputs and outputs are written as CSV files. The ones used are in the input folder, and the result of the operations go to the output folder.

## Makefile

```bash
make .
```
Performs the following operations :
* erosion of the image f1 by square of size 3 (-> ef1_e1.txt)
* erosion of the image f2 by vertical line (|) of size 3 (-> ef2_e2.txt)
* erosion of the image f3 by horizontal line (-) of size 3 (-> ef3_e2.txt)
* erosion of the image f3 by square of size 5 (-> ef3_e3.txt)
* erosion of the image f3 by backward diagonal (\) of size 9 (-> ef3_e4.txt)
* erosion of the image f3 by forward diagonal (/) of size 9 (-> ef3_e5.txt)
* dilation of the image f3 by square of size 5 (-> df3_d3.txt)
* dilation of the image f3 by backward diagonal of size 9 (-> df3_d4.txt)
* dilation of the image f3 by forward diagonal of size 9 (-> df3_d5.txt)
* opening though dilation of 'ef3_e3.txt' by square of size 5 (-> of3_o3.txt)
* opening though dilation of 'ef3_e4.txt' by backward diagonal of size 9 (-> of3_o4.txt)
* opening of the image 'experiment3.png.txt' by forward diagonal of size 3 (-> experiment3_opening.txt)

## Command line 

```bash
cd dilation_erosion_implementation 
./morphological_operation Your_operation se.txt input_image.txt output_image.txt
```

* Your_operation can be : 
  - e : erosion
  - d : dilation
  - opening : opening
 
 * se.txt is the structuring element which is csv file of the binary matrice you want to use 
 
 * the input image should be stored in input folder, the output image should be stored in output folder
