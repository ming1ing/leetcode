# leetcode
## study leetcode

### 001 两数之和<br>
#### 题意：
>找到数组中和为目标值的两个数<br>
#### 解决方法:
>用一个map<int,int>存放数组元素，第一个int值,第二个int放数组下标遍历一下数组用map.find(target-nums[i])找结果<br>

### 002 两数相加
#### 题意：
>给两链表存放两个非负数，但是逆序存放，结也逆序存放
#### 解决方法:
>一位一位加，判断进位，注意一下细节

### 003 无重复字符的最长子串
#### 题意：
>给定一个字符串，找出不含有重复字符的最长子串(连续)的长度
#### 解决方法：
>尺取

### 005 最长回文子串
#### 题意：
>找一个字符串的最长回文子串
#### 解决方法：
>有很多，中心拓展O(n2)，反转后求最长公共子序列O(n2)，manacher算法O(n)

### 006 Z字形变换
#### 题意：
>将一个字符串按z形折叠，然后按行输出
#### 解决方法：
>找规律，模拟

### 007 反转整数
#### 题意：
>整数的数字反转输出
#### 解决方法：
>直接反转，注意范围，可以用long操作，判断是否越界

### 008 字符串转整数 (atoi)
#### 题意：
>把字符串转变成整数
#### 解决方法：
>这题题意简单，实现也简单，但是特别多无效例子,如：+-1,-5-,88888888888888888888,等等

### 009 回文数
#### 题意：
>把整数翻转后与原数比较，相同输出true,不同为false
#### 解决方法：
>负数一定为false，正整数反转一下再计较就行了

### 011 盛最多水的容器
#### 题意：
>从n条垂直线选两条，和x轴形成的容易可以盛最多的水，求容积
#### 解决方法：
>两边不停向内收缩,矮的一段想中间收缩，高的不变，不停更新最大值

### 012 整数转成罗马数字
#### 题意：
>给一个10进制的数转成罗马数字
#### 解决方法：
>因为范围1-3999,所以从千位，到百位，十位，个位，分别转

### 013 罗马数字转整数
#### 题意：
>给一个罗马数字表示的字符串，转成10进制的数
#### 解决方法：
>把4,9这种两个字符组合的先特殊处理，然后再处理单字符

### 014 最长公共前缀
#### 题意：
>找n个字符串的公共前缀
#### 解决方法：
>暴力匹配

### 015 三数之和
#### 题意：
>给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
#### 解决方法：
>先排序,然后用一个变量记住nums[i],在i到len之间找答案O（n2）<br>

### 016 最接近的三数之和
#### 题意：
>给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
#### 解决方法：
>方法同上<br>

### 017 电话号码的字母组合<br>
#### 题意:
>给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合<br>
#### 解决方法：
>dfs<br>

### 018 四数之和
#### 题意：
>给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
#### 解决方法：
>和015，016相同

### 019 删除链表的倒数第N个节点
#### 题意：
>给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点
#### 解决方法：
>为了解决方便在head节点前多加一个空节点，用两个指针一前一后记录相差(n-1)个位置，第三个指针用于删除节点

### 020 有效的括号
#### 题意:
>判断所给的字符串中毒的所有括号是否都匹配
#### 解决方法：
>用栈模拟，左括号进栈，右括号时，判断栈顶元素

### 021 合并两个有序链表
#### 题意：
>合并两条有序链表
#### 解决方法：
>递归合并，小的往后移

### 022 括号生成
#### 题意：
>给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
#### 解决方法：
>dfs。dfs参数记录左括号个数l和右括号的个数r，当l==r时,dfs(l-1,r),当l<r,且当l>0时，dfs(l-1,r),或dfs(l,r-1)

### 023 合并K个排序链表（待优化）<br>
#### 题意：
>合并 k 个排序链表，返回合并后的排序链表<br>
#### 解决方法：
>可以比较k个指针的值的大小，然后生成新的链表复杂度n*k；最好还是用归并n*logk

### 024 两两交换链表中的节点
#### 题意:
>给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
#### 解决方法：
>用三个指针l1指向当前节点，l2指向当前节点的下一个节点，和l3指向当前节点的下一个节点的下一个节点l2->next=l1,然后判断l3的情况，l3为空或者l3没有后记节点（单独一个元素），l1->next=l3为空或者l3没有后记节点（单独一个元素），l1-l3后面还有节点，l1->next=l3->next;l1=l3;前一组的next指针知道后一组的后一个元素，l1，l2指向后一组的两个元素，一直循环操作

### 025 k个一组翻转链表<br>
#### 题意：	
>给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。
#### 解决方法：
>每次把k个反转,一直重复，这题考操作。
		
### 026 删除排序数组中的重复项(待优化)
#### 题意：
>删除有序序列的相同元素
#### 解决方法：
>1的时候直接返回，相同元素往后跳，直至不同元素或结尾，把该元素与第i位交换

### 027  移除元素
#### 题意：
>移除一个数组中所有等于val的元素
#### 解决方法：
>用一个变量anslen记结果长度，遍历时，如果nums[i]不等于val，则把nums[anslen++]=nums[i]

### 028 实现strStr()
#### 题意：
>实现 strStr() 函数。
#### 解决方法：
>KMP算法

### 029 两数相除
#### 题意：
>给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
返回被除数 dividend 除以除数 divisor 得到的商。
#### 解决方法：
>用位运算模拟除法，除数一直左移，商一直乘2，其实就是转成dividend=n1*divisor^n+n2*divisor^(n-1)+...n3比如被除数是10，除数是3，先判断符号，用ans记录结果商，用temp记录当前商，用a记录当前除数10>3,然后a：3*2=6，temp：1*2=2 ; 10>6 然后 a: 6*2=12 ,temp: 2*2=4 ;12>10 ans=0+4/2=2,第二轮 4>3 a:3*2=6 ,temp=1*2=2 ans=ans+2/2=2+1=3;
### 031 下一个排列
#### 题意：
>实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
#### 解决方法：
>从后往前找一个递增序列(最后一个递减序列)，在序列找一个比递增序列前的那个数要大的数交换后，再排序比如1，2，5，4，3,1；后面的递增序列（5，4，3,1），3>2,交换1，3，5，4，2,1 因为2后面的字典序已经最大了，所以只能找比自己大的数字,后面的字典序就要变小，可用数字理解099到100

### 032 最长有效括号<br>
#### 题意:
>给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。<br>
#### 解决方法：
>用两个stack，一个做括号匹配，一个存放id，两个stack同时操作,匹配时把id去掉,留下不匹配的括号和id然后用一个vector记录所有的id，在头尾加上-1和len,然后计算两个id之间的差值 如"(()"
vector数组记录了3，0，-1；3和0之间只有两个数，0和-1之间没有数，所以ans=2,“)()())”,vector数组记录了6，5，0,-1；6和5之间没有数，5和0之间有4个数，0，-1之间没有数，所以ans=4<br>

### 033 搜索旋转排序数组
#### 题意：
>假设按照升序排序的数组在预先未知的某个点上进行了旋转（左移k位，k未知）。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。<br>
#### 解决方法：先用二分查找递减的位置，然后分成两个递增区间再用二分找<br>

### 034 在排序数组中查找元素的第一个和最后一个位置<br>
#### 题意：
>- 给定一个按照升序排列的整数数组 nums，和一个目标值 target。<br>
  找出给定目标值在数组中的开始位置和结束位置。
- 你的算法时间复杂度必须是 O(log n) 级别。
- 如果数组中不存在目标值，返回 [-1, -1]。<br>
#### 解决方法：
>二分，相等的时候特殊处理，判断前后是不是还有，有的话继续迭代

#### 035 搜索插入位置
#### 题意：
>给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回>它将会被按顺序插入的位置。
#### 解决方法：
>二分查找

### 036 有效的数独<br>
#### 题意：
>判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。<br>
>数字 1-9 在每一行只能出现一次。
>数字 1-9 在每一列只能出现一次。
>数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。<br>
#### 解决方法：
根据题意判断即可<br>

### 037 数独
#### 题意：
>编写一个程序，通过已填充的空格来解决数独问题。
#### 解决方法：
>dfs,暴力遍历

### 038 报数
#### 题意：
>把连续的字符串翻译成几个几 ”1“ 翻译成“11” ，“11”翻译成“21”，”111“翻译成”31“...
#### 解决方法：
>应该没有规律，模拟一下就可以，范围只有1-30，很容易过

### 039 组合总数<br>
#### 题意：
>给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数>字和为 target 的组合。
>candidates 中的数字可以无限制重复被选取。<br>
#### 解决方法：
>dfs，搜到一个答案用set存起来

### 040 组合总和 II<br>
#### 题意：
>* 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 >target 的组合。
>* candidates 中的每个数字在每个组合中只能使用一次。<br>
#### 解决方法：
>dfs，用mark数组记录数组元素使用情况，搜到一个答案用set存起来<br>

### 041 缺失的第一个正数
#### 题意：
>给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
#### 解决方法：
>参考了[这位网友](https://blog.csdn.net/wangyuquanliuli/article/details/45749023)的思>路,把nums[i]放到i-1的位置，如果出现重复就跳过
		  
### 042 接雨水
#### 题意：
>给一个柱形图模拟的容器，求可以盛的水的容量
#### 解决方法：
>用两个数组记录每个位置左边最高和右边最高的位置，这两个值的最小值减去当前高度就是该位置可以盛多少水,累加就是总容量

### 043 字符串相乘<br>
#### 题意：
>给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表
>示为字符串形式
#### 解决方法：
>模拟用一个数组记住每一位上的值<br>

### 045 跳跃游戏 II<br>
#### 题意：
>- 给定一个非负整数数组，你最初位于数组的第一个位置。
>- 数组中的每个元素代表你在该位置可以跳跃的最大长度。
>-你的目标是使用最少的跳跃次数到达数组的最后一个位置	<br>
#### 解决方法：
>判断当前位置i+nums[i]是不是比前面的大，如果大，就更新，当i+nums[i]>=len-1，输出步数
		
### 046 全排列
#### 题意：
>给定一个没有重复数字的序列，返回其所有可能的全排列。
#### 解决方法：
>暴力深搜

### 047 全排列 II
#### 题意：
>给定一个可包含重复数字的序列，返回所有不重复的全排列。
#### 解决方法：
>用set对上一题经行处理
		
### 048  旋转图像
#### 题意：
>把n*n的矩阵旋转90°
#### 解决方法：
>把矩阵分成4分，当n为偶数就是(n/2)*(n/2) ,当n为奇数时，(n/2)*((n+1)/2),
>按田字分开，左上角为A，右上角为B，左下角为C，右下角为D
>遍历A中每一个元素，与B,D,C(不是B,C,D)相对应位置的元素进行一次交换即可

### 049 字母异位词分组
#### 题意：
>把一个字符串数组按字母异位分类，字母异位词指字母相同，但排列不同的字符串，即“abc”和“cba”同类 >“abc”和“abd”不同类
#### 解决方法：
>我们可以对字符串内部排序，这样字母异位词就变成一样的排列，为了提高效率，用map<string,int> p字符串记录排序后的字符串int记录vector<vector <string> > ans中第一维记录的字符串对应的下表。例如，”eat“,排序后字符串t为“aet” 在map<string,int>未找到，就添加map.insert(map<string,int>::value_type(t,ans.size()-1));(即map["aet"]=0),num=p[t];ans[num].push_back(strs[i]);num为对应p[t]对应的值。(即num=0,ans[0][0]=strs[0],即”eat“)
		
#### 050 Pow(x,n)
#### 题意：
>算一个数x的n次方
#### 解决方法：
>快速幂。当n为负数转正整数，n每一次右移一位，判断右移后n&1的值是否为1（即判断n的二进制位上是否为1）右移是，x*=x。如，x=2.0,n=10,n的二进制是（1010），x对应的  256 16 4 2 ，然后对应1的有 256 和4 所以结果是256*4=1024

### 051  N皇后
#### 题意：
>n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
#### 解决方法:
>用一个一位数组mark记录哪一列是放了皇后，后面的每一行，遇到mark[i]==1,continue,遇到两条对角线都有‘Q’,continue，直至这一行放不下就return,id>=n时，记录方案


### 052  N皇后II
#### 题意：
>n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
#### 解决方法:
>用一个一位数组mark记录哪一列是放了皇后，后面的每一行，遇到mark[i]==1,continue,遇到两条对角线都有‘Q’,continue，直至这一行放不下就return，id>=n是，ans++，因为向前走，方案不会重复
>

### 053 最大子序和
#### 题意 ：
>给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
#### 解决方法：
>经典的问题,一直往后遍历，用一个计数器,一直外后加，变为负数时，清零，不停更新最大值

### 54. 螺旋矩阵
#### 题意:
>给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
#### 解决方法:
>分成四段来扫描，左上到右上，右上到右下，右下到左下，左下到左上
>注意边界值的判定
### 58. 最后一个单词的长度
#### 题意 ：
>给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
如果不存在最后一个单词，请返回 0 。
#### 解决方法：
>从后往前搜，遇到字母开始搜，空格或者到头结束

### 61.旋转链表
#### 题意：
>给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
#### 解决方法:
>先用快慢指针找到倒数第k的数和k-1的数,然后最后一个数指向第一个数，k-1指向NULL

### 62.不同路径
#### 题意:
>一个机器人位于一个 m x n 网格的左上角机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
问总共有多少条不同的路径？
#### 解决方法:
>由题意可知 :在第一行和第一列的方案数只能是1 
>dp[1][i] =1 (1<=i<=n) dp[j][1]=1(1<=j<=m)
>对于不是第一行和第一列的位置，
>只能由它的左边或者上边来，所以转移方程
>
> - dp[i][j]=dp[i-1][j]+dp[i][j-1] 

### 63.不同路径
#### 题意:
>一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
#### 解决方法:
>方法同上，但是要考虑障碍物就要把有障碍物的位置0
>if(obstacleGrid[i][j]==0)  
>ans[i][j]=ans[i-1][j]+ans[i][j-1];  
>else  
>ans[i][j]=0;

### 64. 最小路径和
#### 题意:
>给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的》>路径，使得路径上的数字总和为最小。
>说明：每次只能向下或者向右移动一步。
#### 解决方法：
>对于第一行和第一列，它们只能来源前一个元素，所以直接累加起来
>对于其他元素,由于只能来源于上或左,所以取这两个值得最小值,再加上本身dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j]

### 69. x 的平方根
#### 题意:
>实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
#### 解决方法:
>二分和牛顿迭代
>
### 70. 爬楼梯
#### 题意:
>假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
>每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
#### 解决方法:
>对于n>=2,它都来源于n-1和n-2的层数的走法,即
>dp[i]=dp[i-1]+dp[i-2]
>
### 82 删除排序链表中的重复元素
#### 题意:
>给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次
#### 解决方法:
>两个指针，phead和pnext,判断phead->val和pnext->val是否相等，相等就删除pnext，否者phead=pnext,pnext=pnext->pnext

### 84 柱状图中最大的矩形
#### 题意:
>给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
>求在该柱状图中，能够勾勒出来的矩形的最大面积。
#### 解决方法:
>最先能想到的就是O(n^2)的方法,每一个位置找到第一个左边比它小l[i]和第一个右边比它小的位置r[i],这样len=r[i]-l[i]-1,更新res=max(len*height[i],res),但是复杂度有点高,所以需要用单调栈来降低复杂度。用一个栈记录一个单调递增的序列，栈只放index，当遇到小于栈顶的元素，就把栈顶元素出栈,因为形成了一个峰,知道了左边和右边界，可以更新res，当前i就是r[i],heigt[stack.top()]就是峰值,l[i]等于stack的第二层(即stack.pop()后的stack.top())；或遇到栈为空，把当前index入栈,长度一般是当前长度或者总长度

### 92. 反转链表 II
#### 题意:
>反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
#### 解决方法:
>先找到第m和第n个节点还有第m个的前一节点ppre，第n个节点后一节点pnext=n->next
>特判一下m==1，直接把m到n反转，然后m->next= pnext,
>否者ppre->next=n ,m->next=pnext
>写法有待优化

### 95. 不同的二叉搜索树 II
#### 题意:
>给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
#### 解决方法:
>和108类似，但是108是生成一种,这题是生成所有,，因此，要把中间结果都保存起来。一开始一直写，发现只有n中情况，发现递归的时候，没有把所有的情况返回,后来看了[https://blog.csdn.net/happyaaaaaaaaaaa/article/details/51635367](https://blog.csdn.net/happyaaaaaaaaaaa/article/details/51635367),发现返回一个递归的结果集就能解决问题了.最好是把递归的结果记录下来，记忆化搜索.
### 96. 不同的二叉搜索树
#### 题意：
>给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
#### 解决方法：
>只要值不同或者结构不同都是不一样，所以结果数目可能很大，用dp做比较合适。当前n个节点，对于x（1<=x<=n）,少于x的有ans[x-1]种方法，大于x的有（n-x）个元素即ans[n-x]个方法,然后左子树的方法数乘右子树的方法数，再累加就是当前x的总个数

### 98  验证二叉搜索树
#### 题意:
>- 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
>假设一个二叉搜索树具有如下特征：
>- 1 节点的左子树只包含小于当前节点的数。
>- 2 节点的右子树只包含大于当前节点的数。
>- 3 所有左子树和右子树自身必须也是二叉搜索树。
#### 解决方法：
>中序遍历进队列或数组，判断是不是升序

### 100 相同的树
#### 题意：
>给定两个二叉树，编写一个函数来检验它们是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
#### 解决方法：
>递归判断，是否都为空，或者值是否相同

### 101 对称二叉树
#### 题意：
>- 给定一个二叉树，检查它是否是镜像对称的。
- 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
#### 解决方法
>- 递归判断，把左右子树进行比较,
>- 迭代，用队列来做,出一个进左右儿子，左树先进右，右树先进左

### 102  二叉树的层次遍历
#### 题意:
>给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
#### 解决方法:
>用队列存放,队列每个元素是一个pair<TreeNode*,int>,第一个是节点指针,第二个是该节点的深度,然后可以根据深度，把每一层的节点的val值放到每一层对应的vector中

### 103 二叉树的锯齿形层次遍历
#### 题意:
>给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
#### 解决方法:
>用两个堆,把奇数层的放在堆一，偶数层放在堆二，先把root放在堆一，
>然后第二层要从右往左，所以直接堆一的元素的左，右儿子放在堆二，偶数层，先放右，再放左。
### 104 二叉树的最大深度
#### 题意:
> 给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
#### 解决方法:
>使用递归,max(左子树深度,右子树深度)+1,叶子节点深度为1

### 105. 从前序与中序遍历序列构造二叉树
#### 题意:
>根据一棵树的前序遍历与中序遍历构造二叉树。  
>*  注意:
你可以假设树中没有重复的元素。
#### 解决方法:
>前序遍历第一个元素一定是根结点,所以，在中序遍历中找到该元素，以该元素为划分点，左边是左子树的中序遍历，右边是右子树的中序遍历，在前序遍历根据中序遍历划分后的长度，把前序遍历再分成左子树的前序遍历和右子树的前序遍历，不停递归。

### 106. 从中序与后序遍历序列构造二叉树
#### 题意:
>根据一棵树的中序遍历与后序遍历构造二叉树。  
>  *  注意:
你可以假设树中没有重复的元素。
#### 解决方法:
>和105类似，后序遍历的最后一个元素为根节点，所以把105的代码相应修改一下就可以了。
### 107 二叉树的层次遍历 II
#### 题意:
>给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
#### 解决方法:
>和102相同,结果使用reverse就可以了

### 108 将有序数组转换为二叉搜索树
#### 题意:
>将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
#### 解决方法:
>递归构造,先选取数组的"中位数"，如果数组元素为偶数，则选中间其中一个,把数组分成两半，root->left指向左半部的"中位数",root->right指向右半部.

### 109. 有序链表转换二叉搜索树
#### 题意:
>给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。  
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
#### 解决方法:
>可以把链表转换成vector，然后使用108的解法.这题就是递归构建一棵树,先用快慢指针找到链表的中点，然后把链表分成两条，然后继续递归。
### 110 平衡二叉树
#### 题意:
>给定一个二叉树，判断它是否是高度平衡的二叉树。  
>本题中，一棵高度平衡二叉树定义为：  
>一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
#### 解决方法:
>由104扩展 ,在回溯的时候比较每一个非叶子结点的左右子树的深度差是否超过1，如果超过1，把答案更新（推荐使用引用）。

### 111. 二叉树的最小深度
#### 题意:
>给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明: 叶子节点是指没有子节点的节点。
#### 解决方法:
>与104类似,但是要注意，一个节点如果只有左（右）子树，就返回该左（右）子树的最小深度+1,当有左右子树时，就返回深度小的。
### 112. 路径总和
#### 题意:
>给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
说明: 叶子节点是指没有子节点的节点。
#### 解决方法:
>直接递归，当该节点是叶子节点且值等于剩下的sum值就返回true，否者false。递归的时候要注意叶子节点才返回。
### 113路径总和 II
#### 题意:
>给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
#### 解决方法:
>用一个vector记录路径，模仿112的做法,当true的时候，把vector放到答案的二维vector里面.

### 118. 杨辉三角
#### 题意：
>给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
#### 解决方法:
>找到递推式`dp[i][j]=dp[i-1][j-1]+dp[i-1][j]`,然后两层for构建就行了;
### 145二叉树的中序遍历
#### 题意：
>给定一个二叉树，返回它的 中序 遍历。
#### 解决方法：
>1. 对于每一个节点，先把他的左儿子，左儿子的左儿子...进栈直至为空<br>
>2. 判断栈顶元素是否有右儿子,没有就输出，有右儿子，先输出父亲节点，再判断是否执行过1，如果已经执行过1，出栈，否者执行1
>当栈为空时结束
>
### 145二叉树的后序遍历
#### 题意：
>给定一个二叉树，返回它的 后序 遍历。
#### 解决方法：
>1. 对于每一个节点，先把他的左儿子，左儿子的左儿子...进栈直至为空<br>
>2. 判断栈顶元素是否有右儿子,没有就输出，有有儿子就判断是否执行过1，如果已经执行过1，就输出，否者执行1
>当栈为空时结束

### 146. LRU缓存机制（待优化）
#### 题意：
>运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。
#### 解决方法：
>使用map来维持map<key,value>,map<id,key>,map<key,id>,第一个map记录数据数据，用于查询；第二个便于查找最远的未被使用的key，第三个是为了更新第二个map

### 172 阶乘后的零
#### 题意：
>给定一个整数 n，返回 n! 结果尾数中零的数量
#### 解决方法：
>其实就是找n里面有多少个因子5，如5有一个，25有两个，。。。找5，25,..5的k次方（小于n），ans=n/5+n/25+...n/(5^k)

### 208 实现 Trie (前缀树)
#### 题意：
>实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
#### 解决方法：
>* insert先定义节点，一个val，一个26个指针的数组,insert是一直插入，没有就new，然后root=root->next[i],单词的最后一个字母的val为1<br>
>* search要一直搜索，如果为NULL就是false，最后一个字母的val为0，也是false
>* startWith和search相似，但是最后一个字母的val为0时，返回true

### 215  数组中的第K个最大元素
#### 题意：
>在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
#### 解决方法:
>如果可以掉乱顺序，用快排的思想可以O(N),元素不可以换位置，用二进制排序o(log(max)*N)

### 226. 翻转二叉树
#### 题意:
>翻转一棵二叉树。
#### 解决方法:
>调换左右儿子节点，一直递归
### 486. 预测赢家
#### 题意：
>给定一个表示分数的非负整数数组。 玩家1从数组任意一端拿取一个分数，随后玩家2继续从剩余数组任意一端拿取分数，然后玩家1拿，……。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。
给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化
#### 解决方法:
>搜索，也可以用dp

### 535TinyURL 的加密与解密
#### 题意：
>* TinyURL是一种URL简化服务， 比如：当你输入一个URL https://leetcode.com/problems/design-tinyurl 时，它将返回一个简化的URL http://tinyurl.com/4e9iAk.
* 要求：设计一个 TinyURL 的加密 encode 和解密 decode 的方法。你的加密和解密算法如何设计和运作是没有限制的，你只需要保证一个URL可以被加密成一个TinyURL，并且这个TinyURL可以用解密方法恢复成原本的URL。
#### 解决方法:
>用两个map，map<longURL,shortURL>,map<shortURL,longURL>,因为网站题目不会超过2^64次方，所以直接用id简化，但是空间复杂度有点高
>最好还是用加密算法
### 697 数组的度
#### 题意
>给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。
你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
#### 解决方法
>我们可以用一个map记录每一个不同的元素的最早出现位置和最晚出现位置，以及出现次数，根据这些可以使时间复杂度达到O(NlogN)

### 876链表的中间结点
#### 题意：
>给定一个带有头结点 head 的非空单链表，返回链表的中间结点。<br>
>如果有两个中间结点，则返回第二个中间结点。
#### 解决方法：
>用快慢指针，慢指针移动一步，快指针移动两步

### 897. 递增顺序查找树
#### 题意:
>给定一个树，按中序遍历重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点
#### 解决方法:
>先用一个vector存放中序遍历的结果，然后再构建一棵退化树。