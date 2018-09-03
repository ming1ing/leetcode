# leetcode
##study leetcode

###001 两数之和<br>
####题意：
>找到数组中和为目标值的两个数<br>
####解决方法:
>用一个map<int,int>存放数组元素，第一个int值,第二个int放数组下标遍历一下数组用map.find(target-nums[i])找结果<br>

###002 两数相加
####题意：
>给两链表存放两个非负数，但是逆序存放，结也逆序存放
####解决方法:
>一位一位加，判断进位，注意一下细节

###003 无重复字符的最长子串
####题意：
>给定一个字符串，找出不含有重复字符的最长子串(连续)的长度
####解决方法：
>尺取

###005 最长回文子串
####题意：
>找一个字符串的最长回文子串
####解决方法：
>有很多，中心拓展O(n2)，反转后求最长公共子序列O(n2)，manacher算法O(n)

###006 Z字形变换
####题意：
>将一个字符串按z形折叠，然后按行输出
####解决方法：
>找规律，模拟

###007 反转整数
####题意：
>整数的数字反转输出
####解决方法：
>直接反转，注意范围，可以用long操作，判断是否越界

###008 字符串转整数 (atoi)
####题意：
>把字符串转变成整数
####解决方法：
>这题题意简单，实现也简单，但是特别多无效例子,如：+-1,-5-,88888888888888888888,等等

###009 回文数
####题意：
>把整数翻转后与原数比较，相同输出true,不同为false
####解决方法：
>负数一定为false，正整数反转一下再计较就行了

###011 盛最多水的容器
####题意：
>从n条垂直线选两条，和x轴形成的容易可以盛最多的水，求容积
####解决方法：
>两边不停向内收缩,矮的一段想中间收缩，高的不变，不停更新最大值

###012 整数转成罗马数字
####题意：
>给一个10进制的数转成罗马数字
####解决方法：
>因为范围1-3999,所以从千位，到百位，十位，个位，分别转

###013 罗马数字转整数
####题意：
>给一个罗马数字表示的字符串，转成10进制的数
####解决方法：
>把4,9这种两个字符组合的先特殊处理，然后再处理单字符

###014 最长公共前缀
####题意：
>找n个字符串的公共前缀
####解决方法：
>暴力匹配

###015 三数之和
####题意：
>给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
####解决方法：
>先排序,然后用一个变量记住nums[i],在i到len之间找答案O（n2）<br>

###016 最接近的三数之和
####题意：
>给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
####解决方法：
>方法同上<br>

###017 电话号码的字母组合<br>
####题意:
>给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合<br>
####解决方法：
>dfs<br>

###018 四数之和
####题意：
>给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
####解决方法：
>和015，016相同

###019 删除链表的倒数第N个节点
####题意：
>给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点
####解决方法：
>为了解决方便在head节点前多加一个空节点，用两个指针一前一后记录相差(n-1)个位置，第三个指针用于删除节点

###020 有效的括号
####题意:
>判断所给的字符串中毒的所有括号是否都匹配
####解决方法：
>用栈模拟，左括号进栈，右括号时，判断栈顶元素

###021 合并两个有序链表
####题意：
>合并两条有序链表
####解决方法：
>递归合并，小的往后移

###022 括号生成
####题意：
>给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
####解决方法：
>dfs。dfs参数记录左括号个数l和右括号的个数r，当l==r时,dfs(l-1,r),当l<r,且当l>0时，dfs(l-1,r),或dfs(l,r-1)

###023 合并K个排序链表（待优化）<br>
####题意：
>合并 k 个排序链表，返回合并后的排序链表<br>
####解决方法：
>可以比较k个指针的值的大小，然后生成新的链表复杂度n*k；最好还是用归并n*logk

###024 两两交换链表中的节点
####题意:
>给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
####解决方法：
>用三个指针l1指向当前节点，l2指向当前节点的下一个节点，和l3指向当前节点的下一个节点的下一个节点l2->next=l1,然后判断l3的情况，l3为空或者l3没有后记节点（单独一个元素），l1->next=l3为空或者l3没有后记节点（单独一个元素），l1-l3后面还有节点，l1->next=l3->next;l1=l3;前一组的next指针知道后一组的后一个元素，l1，l2指向后一组的两个元素，一直循环操作

###025 k个一组翻转链表<br>
####题意：	
>给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。
####解决方法：
>每次把k个反转,一直重复，这题考操作。
		
###026 删除排序数组中的重复项(待优化)
####题意：
>删除有序序列的相同元素
####解决方法：
>1的时候直接返回，相同元素往后跳，直至不同元素或结尾，把该元素与第i位交换

###027  移除元素
####题意：
>移除一个数组中所有等于val的元素
####解决方法：
>用一个变量anslen记结果长度，遍历时，如果nums[i]不等于val，则把nums[anslen++]=nums[i]

###028 实现strStr()
####题意：
>实现 strStr() 函数。
####解决方法：
>KMP算法

###029 两数相除
####题意：
>给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
返回被除数 dividend 除以除数 divisor 得到的商。
####解决方法：
>用位运算模拟除法，除数一直左移，商一直乘2，其实就是转成dividend=n1*divisor^n+n2*divisor^(n-1)+...n3比如被除数是10，除数是3，先判断符号，用ans记录结果商，用temp记录当前商，用a记录当前除数10>3,然后a：3*2=6，temp：1*2=2 ; 10>6 然后 a: 6*2=12 ,temp: 2*2=4 ;12>10 ans=0+4/2=2,第二轮 4>3 a:3*2=6 ,temp=1*2=2 ans=ans+2/2=2+1=3;
###031 下一个排列
####题意：
>实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
####解决方法：
>从后往前找一个递增序列(最后一个递减序列)，在序列找一个比递增序列前的那个数要大的数交换后，再排序比如1，2，5，4，3,1；后面的递增序列（5，4，3,1），3>2,交换1，3，5，4，2,1 因为2后面的字典序已经最大了，所以只能找比自己大的数字,后面的字典序就要变小，可用数字理解099到100

###032 最长有效括号<br>
####题意:
>给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。<br>
####解决方法：
>用两个stack，一个做括号匹配，一个存放id，两个stack同时操作,匹配时把id去掉,留下不匹配的括号和id然后用一个vector记录所有的id，在头尾加上-1和len,然后计算两个id之间的差值 如"(()"
vector数组记录了3，0，-1；3和0之间只有两个数，0和-1之间没有数，所以ans=2,“)()())”,vector数组记录了6，5，0,-1；6和5之间没有数，5和0之间有4个数，0，-1之间没有数，所以ans=4<br>

###033 搜索旋转排序数组
####题意：
>假设按照升序排序的数组在预先未知的某个点上进行了旋转（左移k位，k未知）。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。<br>
####解决方法：先用二分查找递减的位置，然后分成两个递增区间再用二分找<br>

###034 在排序数组中查找元素的第一个和最后一个位置<br>
####题意：
>- 给定一个按照升序排列的整数数组 nums，和一个目标值 target。<br>
  找出给定目标值在数组中的开始位置和结束位置。
- 你的算法时间复杂度必须是 O(log n) 级别。
- 如果数组中不存在目标值，返回 [-1, -1]。<br>
####解决方法：
>二分，相等的时候特殊处理，判断前后是不是还有，有的话继续迭代

####035 搜索插入位置
####题意：
>给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回>它将会被按顺序插入的位置。
####解决方法：
>二分查找

###036 有效的数独<br>
####题意：
>判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。<br>
>数字 1-9 在每一行只能出现一次。
>数字 1-9 在每一列只能出现一次。
>数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。<br>
####解决方法：
根据题意判断即可<br>

###037 数独
####题意：
>编写一个程序，通过已填充的空格来解决数独问题。
####解决方法：
>dfs,暴力遍历

###038 报数
####题意：
>把连续的字符串翻译成几个几 ”1“ 翻译成“11” ，“11”翻译成“21”，”111“翻译成”31“...
####解决方法：
>应该没有规律，模拟一下就可以，范围只有1-30，很容易过

###039 组合总数<br>
####题意：
>给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数>字和为 target 的组合。
>candidates 中的数字可以无限制重复被选取。<br>
####解决方法：
>dfs，搜到一个答案用set存起来

###040 组合总和 II<br>
####题意：
>* 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 >target 的组合。
>* candidates 中的每个数字在每个组合中只能使用一次。<br>
####解决方法：
>dfs，用mark数组记录数组元素使用情况，搜到一个答案用set存起来<br>

###041 缺失的第一个正数
####题意：
>给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
####解决方法：
>参考了[这位网友](https://blog.csdn.net/wangyuquanliuli/article/details/45749023)的思>路,把nums[i]放到i-1的位置，如果出现重复就跳过
		  
###042 接雨水
####题意：
>给一个柱形图模拟的容器，求可以盛的水的容量
####解决方法：
>用两个数组记录每个位置左边最高和右边最高的位置，这两个值的最小值减去当前高度就是该位置可以盛多少水,累加就是总容量

###043 字符串相乘<br>
####题意：
>给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表
>示为字符串形式
####解决方法：
>模拟用一个数组记住每一位上的值<br>

###045 跳跃游戏 II<br>
####题意：
>- 给定一个非负整数数组，你最初位于数组的第一个位置。
>- 数组中的每个元素代表你在该位置可以跳跃的最大长度。
>-你的目标是使用最少的跳跃次数到达数组的最后一个位置	<br>
####解决方法：
>判断当前位置i+nums[i]是不是比前面的大，如果大，就更新，当i+nums[i]>=len-1，输出步数
		
###046 全排列
####题意：
>给定一个没有重复数字的序列，返回其所有可能的全排列。
####解决方法：
>暴力深搜

###047 全排列 II
####题意：
>给定一个可包含重复数字的序列，返回所有不重复的全排列。
####解决方法：
>用set对上一题经行处理
		
###048  旋转图像
####题意：
>把n*n的矩阵旋转90°
####解决方法：
>把矩阵分成4分，当n为偶数就是(n/2)*(n/2) ,当n为奇数时，(n/2)*((n+1)/2),
>按田字分开，左上角为A，右上角为B，左下角为C，右下角为D
>遍历A中每一个元素，与B,D,C(不是B,C,D)相对应位置的元素进行一次交换即可

###049 字母异位词分组
####题意：
>把一个字符串数组按字母异位分类，字母异位词指字母相同，但排列不同的字符串，即“abc”和“cba”同类 >“abc”和“abd”不同类
####解决方法：
>我们可以对字符串内部排序，这样字母异位词就变成一样的排列，为了提高效率，用map<string,int> p字符串记录排序后的字符串int记录vector<vector <string> > ans中第一维记录的字符串对应的下表。例如，”eat“,排序后字符串t为“aet” 在map<string,int>未找到，就添加map.insert(map<string,int>::value_type(t,ans.size()-1));(即map["aet"]=0),num=p[t];ans[num].push_back(strs[i]);num为对应p[t]对应的值。(即num=0,ans[0][0]=strs[0],即”eat“)
		
####050 Pow(x,n)
####题意：
>算一个数x的n次方
####解决方法：
>快速幂。当n为负数转正整数，n每一次右移一位，判断右移后n&1的值是否为1（即判断n的二进制位上是否为1）右移是，x*=x。如，x=2.0,n=10,n的二进制是（1010），x对应的  256 16 4 2 ，然后对应1的有 256 和4 所以结果是256*4=1024

###145二叉树的中序遍历
####题意：
>给定一个二叉树，返回它的 中序 遍历。
####解决方法：
>1. 对于每一个节点，先把他的左儿子，左儿子的左儿子...进栈直至为空<br>
>2. 判断栈顶元素是否有右儿子,没有就输出，有右儿子，先输出父亲节点，再判断是否执行过1，如果已经执行过1，出栈，否者执行1
>当栈为空时结束
>
###145二叉树的后序遍历
####题意：
>给定一个二叉树，返回它的 后序 遍历。
####解决方法：
>1. 对于每一个节点，先把他的左儿子，左儿子的左儿子...进栈直至为空<br>
>2. 判断栈顶元素是否有右儿子,没有就输出，有有儿子就判断是否执行过1，如果已经执行过1，就输出，否者执行1
>当栈为空时结束

###172 阶乘后的零
####题意：
>给定一个整数 n，返回 n! 结果尾数中零的数量
####解决方法：
>其实就是找n里面有多少个因子5，如5有一个，25有两个，。。。找5，25,..5的k次方（小于n），ans=n/5+n/25+...n/(5^k)

###208 实现 Trie (前缀树)
####题意：
>实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
####解决方法：
>* insert先定义节点，一个val，一个26个指针的数组,insert是一直插入，没有就new，然后root=root->next[i],单词的最后一个字母的val为1<br>
>* search要一直搜索，如果为NULL就是false，最后一个字母的val为0，也是false
>* startWith和search相似，但是最后一个字母的val为0时，返回true

###876链表的中间结点
####题意：
>给定一个带有头结点 head 的非空单链表，返回链表的中间结点。<br>
>如果有两个中间结点，则返回第二个中间结点。
####解决方法：
>用快慢指针，慢指针移动一步，快指针移动两步