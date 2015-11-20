# small-prog
Usual small program

11月20号，我翻了下C专家编程，有一道题目是关于回文的。
本想（试者）着手解决，可是发现找不到全英文的名词表，网上搜到的都是带有中文翻译。
于是我根据下载得来的txt文件内容，写了个小程序来提取出里面的单词。

三个程序均在windows命令行运行，格式：prog inputfilename outputfilename
txt2englishword是第一文本文件(inputfilename)里的所有英语单词提取出来，添加到outputfilename文件里。
sort：由txt2englishword得到的输出文件排序。
unique：由txt2englishword得到的文件排序和去除重复的单词。

注：1. c format 是指经程序得到的输出文件可以被C程序正确读取。
     manf format 是为了方便阅读，文件一行只有10个单词。（可能加了'\n'转行符，以至于C程序只能读取第一行，重复读取第一行最后一个单词）
    2.两次sort可以得到排序并单词唯一的文件。详看源代码里的一行注释。


