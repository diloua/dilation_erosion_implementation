
import numpy as np
import csv
from PIL import Image
import csv
import sys

with open(sys.argv[1]) as f:
    output = [int(s) for line in f.readlines() for s in line[:-1].split(',')]
counter = dict()
row=output
pixels=output
pixels = np.array(pixels, dtype='uint8')
pixels = pixels.reshape((int(sys.argv[2]), int(sys.argv[2])))
image = Image.fromarray(pixels)

filename = '{}{}.png'.format(sys.argv[1], "result")

image.save(filename)

print('saved:', filename)
