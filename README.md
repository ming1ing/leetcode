# leetcode
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
