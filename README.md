﻿# leetcode
study leetcode

001 两数之和
题意：找到数组中和为目标值的两个数
解决方法:用一个map<int,int>存放数组元素，第一个int值,第二个int放数组下标
		遍历一下数组用map.find(target-nums[i])找结果
		
002 两数相加
题意：给两链表存放两个非负数，但是逆序存放，结也逆序存放
解决方法:一位一位加，判断进位，注意一下细节

003 无重复字符的最长子串
题意：给定一个字符串，找出不含有重复字符的最长子串(连续)的长度
解决方法：尺取

005 最长回文子串
题意：找一个字符串的最长回文子串
解决方法：有很多，中心拓展O(n2)，反转后求最长公共子序列O(n2)，manacher算法O(n)

006 Z字形变换
题意：将一个字符串按z形折叠，然后按行输出
解决方法：找规律，模拟

007 反转整数
题意：整数的数字反转输出
解决方法：直接反转，注意范围，可以用long操作，判断是否越界

008 字符串转整数 (atoi)
题意：把字符串转变成整数
解决方法：这题题意简单，实现也简单，但是特别多无效例子,如：+-1,-5-,88888888888888888888,等等

009 回文数
题意：把整数翻转后与原数比较，相同输出true,不同为false
解决方法：负数一定为false，正整数反转一下再计较就行了

011 盛最多水的容器
题意：从n条垂直线选两条，和x轴形成的容易可以盛最多的水，求容积
解决方法：两边不停向内收缩,矮的一段想中间收缩，高的不变，不停更新最大值

012 整数转成罗马数字
题意：给一个10进制的数转成罗马数字
解决方法：因为范围1-3999,所以从千位，到百位，十位，个位，分别转

013 罗马数字转整数
题意：给一个罗马数字表示的字符串，转成10进制的数
解决方法：把4,9这种两个字符组合的先特殊处理，然后再处理单字符

014 最长公共前缀
题意：找n个字符串的公共前缀
解决方法：暴力匹配

019 删除链表的倒数第N个节点
题意：给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点
解决方法：为了解决方便在head节点前多加一个空节点，用两个指针一前一后记录相差(n-1)个位置，第三个指针用于删除节点

020 有效的括号
题意:判断所给的字符串中毒的所有括号是否都匹配
解决方法：用栈模拟，左括号进栈，右括号时，判断栈顶元素

021 合并两个有序链表
题意：合并两条有序链表
解决方法：递归合并，小的往后移

026 删除排序数组中的重复项(待优化)
题意：删除有序序列的相同元素
解决方法：1的时候直接返回，相同元素往后跳，直至不同元素或结尾，把该元素与第i位交换

027  移除元素
题意：移除一个数组中所有等于val的元素
解决方法：用一个变量anslen记结果长度，遍历时，如果nums[i]不等于val，则把nums[anslen++]=nums[i]
