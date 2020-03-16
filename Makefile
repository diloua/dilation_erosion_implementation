CC=g++
CFLAGS=-std=c++0x

run: hw_fd.cpp
	$(CC) $(CFLAGS) -o hw_fd hw_fd.cpp
	./hw_fd e SE_3x3_ square.txt f1.txt ef1_e1.txt 
	./hw_fd e SE_3x3_vertical.txt f2.txt ef2_e2.txt
	./hw_fd e SE_3x3_horizental.txt f3.txt ef3_e2.txt
	./hw_fd e SE_5x5_square.txt f3.txt ef3_e3.txt
	./hw_fd e SE_bdiagonal.txt f3.txt ef3_e4.txt
	./hw_fd e SE_fdiagonal.txt f3.txt ef3_e5.txt
	./hw_fd d SE_5x5_square.txt f3.txt df3_d4.txt
	./hw_fd d SE_bdiagonal.txt f3.txt df3_d4.txt
	./hw_fd d SE_fdiagonal.txt f3.txt df3_d5:txt
	./hw_fd d SE_5x5_square.txt ef3_e3.txt of3_o3.txt
	./hw_fd d SE_bdiagonal.txt ef3_e4.txt of3_o4.txt
	./hw_fd e SE_assymetric.txt assymetric_experiment.png.txt assymetric_experiment_erosion.txt
	./hw_fd e SE_3x3_square.txt experiment1.png.txt experiment1_erosion.txt
	./hw_fd d SE_5x5_exp2.txt experiment2.png.txt experiment2_dilation.txt
	./hw_fd opening SE_3x3_fdiagonal.txt experiment3.png.txt experiment3_opening.txt
