RuHash
======

Hash algorithm

1. Begin (information of all size) 
2. Generating salt & whitening it
3. Adding information to achieve the full block (128,256..)
4. Salting & whitening added information 
5. Folding all information in 32-bit block 
6. Whitening the block 
7. Result (32-bit hash)

На вход алгоритма подается информация любой длины, затем она дополняется до 128, 256, 512.. блока символов. Ключевая особенность алгоритма - отбеливание. Это специальная функция, которая выполняет подбор числа или символа на основе входного числа. На выходе алгоритма получается 32-битная строка, содержащая символы a-z, A-Z, 0-9.
