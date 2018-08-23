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

017 电话号码的字母组合<br>
题意:给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合<br>
解决方法：dfs<br>

019 删除链表的倒数第N个节点
题意：给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点
解决方法：为了解决方便在head节点前多加一个空节点，用两个指针一前一后记录相差(n-1)个位置，第三个指针用于删除节点

020 有效的括号
题意:判断所给的字符串中毒的所有括号是否都匹配
解决方法：用栈模拟，左括号进栈，右括号时，判断栈顶元素

021 合并两个有序链表
题意：合并两条有序链表
解决方法：递归合并，小的往后移

022 括号生成
题意：给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
解决方法：dfs。dfs参数记录左括号个数l和右括号的个数r，当l==r时,dfs(l-1,r),当l<r,且当l>0时，dfs(l-1,r),或dfs(l,r-1)

024 两两交换链表中的节点
题意:给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
解决方法：用三个指针l1指向当前节点，l2指向当前节点的下一个节点，和l3指向当前节点的下一个节点的下一个节点
			l2->next=l1,然后判断l3的情况，l3为空或者l3没有后记节点（单独一个元素），l1->next=l3为空或者l3没有后记节点（单独一个元素），l1-
			l3后面还有节点，l1->next=l3->next;l1=l3;前一组的next指针知道后一组的后一个元素，l1，l2指向后一组的两个元素，一直循环操作
			
026 删除排序数组中的重复项(待优化)
题意：删除有序序列的相同元素
解决方法：1的时候直接返回，相同元素往后跳，直至不同元素或结尾，把该元素与第i位交换

027  移除元素
题意：移除一个数组中所有等于val的元素
解决方法：用一个变量anslen记结果长度，遍历时，如果nums[i]不等于val，则把nums[anslen++]=nums[i]

029 两数相除
题意：给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
	  返回被除数 dividend 除以除数 divisor 得到的商。
解决方法：用位运算模拟除法，除数一直左移，商一直乘2，其实就是转成dividend=n1*divisor^n+n2*divisor^(n-1)+...n3
		  比如被除数是10，除数是3，先判断符号，用ans记录结果商，用temp记录当前商，用a记录当前除数
			10>3,然后a：3*2=6，temp：1*2=2 ; 10>6 然后 a: 6*2=12 ,temp: 2*2=4 ;12>10 ans=0+4/2=2,
			第二轮 4>3 a:3*2=6 ,temp=1*2=2 ans=ans+2/2=2+1=3;

032 最长有效括号<br>
题意:给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。<br>
解决方法：用两个stack，一个做括号匹配，一个存放id，两个stack同时操作,匹配时把id去掉,留下不匹配的括号和id
			然后用一个vector记录所有的id，在头尾加上-1和len,然后计算两个id之间的差值 如"(()"
			vector数组记录了3，0，-1；3和0之间只有两个数，0和-1之间没有数，所以ans=2
			“)()())”,vector数组记录了6，5，0,-1；6和5之间没有数，5和0之间有4个数，0，-1之间没有数，所以ans=4<br>
			
035 搜索插入位置
题意：给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
解决方法：二分查找

038 报数
题意：把连续的字符串翻译成几个几 ”1“ 翻译成“11” ，“11”翻译成“21”，”111“翻译成”31“...
解决方法：应该没有规律，模拟一下就可以，范围只有1-30，很容易过

042 接雨水
题意：给一个柱形图模拟的容器，求可以盛的水的容量
解决方法：用两个数组记录每个位置左边最高和右边最高的位置，这两个值的最小值减去当前高度就是该位置可以省多少水
			累加就是总容量

045 跳跃游戏 II<br>
题意：给定一个非负整数数组，你最初位于数组的第一个位置。
		数组中的每个元素代表你在该位置可以跳跃的最大长度。
		你的目标是使用最少的跳跃次数到达数组的最后一个位置	<br>
解决方法：判断当前位置i+nums[i]是不是比前面的大，如果大，就更新，当i+nums[i]>=len-1，输出步数
		
046 全排列
题意：给定一个没有重复数字的序列，返回其所有可能的全排列。
解决方法：暴力深搜

047 全排列 II
题意：给定一个可包含重复数字的序列，返回所有不重复的全排列。
解决方法：用set对上一题经行处理
		
048  旋转图像
题意：把n*n的矩阵旋转90°
解决方法：把矩阵分成4分，当n为偶数就是(n/2)*(n/2) ,当n为奇数时，(n/2)*((n+1)/2),
			按田字分开，左上角为A，右上角为B，左下角为C，右下角为D
			遍历A中每一个元素，与B,D,C(不是B,C,D)相对应位置的元素进行一次交换即可

049 字母异位词分组
题意：把一个字符串数组按字母异位分类，字母异位词指字母相同，但排列不同的字符串，即“abc”和“cba”同类 “abc”和“abd”不同类
解决方法：我们可以对字符串内部排序，这样字母异位词就变成一样的排列，为了提高效率，用map<string,int> p字符串记录排序后的字符串
		int记录vector<vector <string> > ans中第一维记录的字符串对应的下表。例如，”eat“,排序后字符串t为“aet” 在map<string,int>
		未找到，就添加map.insert(map<string,int>::value_type(t,ans.size()-1));(即map["aet"]=0)
		num=p[t];ans[num].push_back(strs[i]);num为对应p[t]对应的值。(即num=0,ans[0][0]=strs[0],即”eat“)
		
050 Pow(x,n)
题意：算一个数x的n次方
解决方法：快速幂。当n为负数转正整数，n每一次右移一位，判断右移后n&1的值是否为1（即判断n的二进制位上是否为1）
		右移是，x*=x。如，x=2.0,n=10,n的二进制是（1010），x对应的  256 16 4 2 ，然后对应1的有 256 和4 所以结果是256*4=1024
		