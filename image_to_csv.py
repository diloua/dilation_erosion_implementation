import numpy as np
import sys
from PIL import Image
img = np.array(Image.open(sys.argv[1]))

import csv

def csvWriter(fil_name, nparray):
  example = nparray.tolist()
  with open(fil_name+'.txt', 'w', newline='') as csvfile:
    writer = csv.writer(csvfile, delimiter=',')
    writer.writerows(example)

csvWriter(sys.argv[1], img)
