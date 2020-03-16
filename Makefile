CC=g++
CFLAGS=-std=c++0x

run: morphological_operation.cpp
	$(CC) $(CFLAGS) -o morphological_operation.cpp
	./morphological_operation e SE_3x3_ square.txt f1.txt ef1_e1.txt 
	./morphological_operation e SE_3x3_vertical.txt f2.txt ef2_e2.txt
	./morphological_operation e SE_3x3_horizental.txt f3.txt ef3_e2.txt
	./morphological_operation e SE_5x5_square.txt f3.txt ef3_e3.txt
	./morphological_operation e SE_bdiagonal.txt f3.txt ef3_e4.txt
	./morphological_operation e SE_fdiagonal.txt f3.txt ef3_e5.txt
	./morphological_operation d SE_5x5_square.txt f3.txt df3_d4.txt
	./morphological_operation d SE_bdiagonal.txt f3.txt df3_d4.txt
	./morphological_operation d SE_fdiagonal.txt f3.txt df3_d5:txt
	./morphological_operation d SE_5x5_square.txt ef3_e3.txt of3_o3.txt
	./morphological_operation d SE_bdiagonal.txt ef3_e4.txt of3_o4.txt
	./morphological_operation e SE_assymetric.txt assymetric_experiment.png.txt assymetric_experiment_erosion.txt
	./morphological_operation opening SE_3x3_fdiagonal.txt experiment3.png.txt experiment3_opening.txt
