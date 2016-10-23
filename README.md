# USACO-training

## 3.3

1) ride the fences  欧拉道路,dfs,倒序输出

2) shopping	    dp问题

3) Camelot    类似spfa修正国王的步数

4) Home on the range   模拟//  其实可以dp

5) A Game 博弈问题，dp解决

## 3.4

1) 前序中序输出后序

2) electric fence  数学问题，有点意思。用到皮克定理

3) Rockers	dp问题,和上面的A Game比较像

## 4.1

1) Nuggets	数论,n个数，不能组合出的最大数不超过两个最大数的最大公倍数

2) 

## 4.2

1) Drainage Ditches 最大网络流问题,EK算法

2) The Perfect Stall 二分图匹配,hungary算法

3) Job Processing		时序拼接

## 4.3

1) Buy Low, Buy Lower	dp问题

2) Street Race			多次dfs寻找必须经过的点，第二问略恶心

3) Letter Game			全排列找所有情况

## 4.4

1) Shuttle Puzzle		比较简单，下棋问题，递归解决

2) Pollutant Control	找最小割集，题目给的测试数据不全面，导致自己的程序不完备也过了…//测试数据应该没有多个最小割

3) Frame Up				方框覆盖，基本想法就是DFS…

## 5.1

1) Fencing the Cows		凸包，graham算法(格拉汉扫描法)

2) starry night			比较水，floodFill + string判断状态(配合星星范围和数量剪枝)

3) musical theme		水题，纯纯的暴力找最长重复子串

## 5.2

1) snail trail			水题，单纯DFS，最开始出了点小bug，没有考虑虽然没有踩到自己但是也无路可走的情况

## 5.3

1) milk measuring	迭代加深搜索＋完全背包dp

2) window area	开始想了一天没啥想法就放下了，周五英语课上发觉可以用递归做。开始的想法是递归求被cover的面积，感觉代码冗长，不用了作废，后来换思路求没有被cover的面积，代码很短

3) school network		两次dfs（kosaraju算法）求解有多少强联通分量（缩点）

4) big barn dp问题

## 5.4

1) Canada tour		这个dp我是服的，真服，迷一般的套路。

2) charrec

3) TeleCowmunication		求无向图的最小割点集，类似于最大流。求割点个数时多次BFS，若找到一条路径++flow，同时删掉路径上的点。

## 5.5

1) picture 题目大意：一个2000*2000的平面，随机投放长方形，长方形会重叠，求最终形成图形的周长。因为横边和竖边情况完全类似，可将2维降维为1维，因为有些边会被覆盖，类似括号匹配问题，以｛｝［］（）表示三个矩形，比如覆盖情况为｛［］｝（），化简为（（））（），被包涵的括号作废，剩下（）（），将边按出现顺序排序。

2) hidden题目大意：一个字符串长为L，收尾相连，找出所有L个循环字符串中最小的那个的首字母在原来字符串中的位置。暴力搜索。设置两个起始标志i，j分别指向两个正在被比较的字符串起始地只，寻找相同前缀，长为k－1，比较s[i+k] s[j+k] , s[i+k]<s[j+k]则j=j+k+1,i不变，s[i+k] >s[j+k]则i = j,++j; ans保存在i。



