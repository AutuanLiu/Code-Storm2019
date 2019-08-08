#!/usr/bin/env python
# coding: utf-8

import tensorflow as tf
import numpy as np

# - eager 模式即立即执行的模式，不需要构建静态图
tf.enable_eager_execution()
tfe = tf.contrib.eager
print(tf.executing_eagerly())

print(tf.multiply(6, 7).numpy())    # 直接执行 不用session.run

a = tf.constant(2)
b = tf.constant(5)
c = a * b
print(a, b, c, sep='\n')

np.multiply(a, b)    # 可以直接使用 numpy 计算

# tf 和 numpy 可以混合起来进行计算
x = tf.constant([[1., 2.], [5., 6.2]], dtype=tf.float64)
y = np.array([[3.4, 5.1], [3.2, 4.1]], dtype=np.float64)
print(x, y, x @ y, x * y, sep='\n')

print(np.matmul(x, y))
print(tf.matmul(tf.cast(x, tf.float64), tf.cast(y, tf.float64)))
