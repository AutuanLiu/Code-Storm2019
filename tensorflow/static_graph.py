# 使用静态图模式
import tensorflow as tf

a = tf.constant(2)
b = tf.constant(3)

add = tf.add(a, b)
mul = tf.multiply(a, b)
with tf.Session() as sess:
    x = sess.run(add)
    y = sess.run(mul)
    print(f'x {x} y {y}')
