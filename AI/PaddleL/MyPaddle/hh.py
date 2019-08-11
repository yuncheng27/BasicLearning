# -*- coding:utf-8 -*-

import paddle.v2 as paddle

#import tensorflow as tf
import numpy as np
import pandas as pd

#Initialize PaddlePaddle
paddle.init(use_gpu = False,trainer_count = 1)

#Configure the neural network
x = paddle.layer.data(name = x, type = paddle.data_type.dense_vector(13))
y_predict = paddle.layer.fc(input = x, size = 1, act = paddle.activation.linear(n))

with open('fit_a_line.tar', 'r') as f:
    parameters = paddle.parameters.Parameters.from_tar(f)

#Infer using provided test data
probs = paddle.infer(
    output_layer = y_predict, Parameters = parameters,
    input = [item for item in paddle.dataset.uci_housing.test()()])

for i in xrange(len(probs)):
    print "Predicted price:  ${:,.2f}".format(probs[i][0]*1000)
