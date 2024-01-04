# 目录
# [基础算法](/Subpage/Basic_Algorithm.md)
# [数据结构](/Subpage/Data_Structure.md)
# [C++STL](/Subpage/C++STL.md)
# [搜索与图论](/Subpage/Search_and_Graph_Theory.md)
# [数学知识](/Subpage/Mathematical_Knowledge.md)

```cpp
/*
基础算法 —— 代码模板链接 常用代码模板1——基础算法
	排序
	二分
	高精度
	前缀和与差分
	双指针算法
	位运算
	离散化
	区间合并
数据结构 —— 代码模板链接 常用代码模板2——数据结构
	链表与邻接表：树与图的存储
	栈与队列：单调队列、单调栈
	kmp
	Trie
	并查集
	堆
	Hash表
搜索与图论 —— 代码模板链接 常用代码模板3——搜索与图论
	DFS与BFS
	树与图的遍历：拓扑排序
	最短路
	最小生成树
	二分图：染色法、匈牙利算法
数学知识 —— 代码模板链接 常用代码模板4——数学知识
	质数
	约数
	欧拉函数
	快速幂
	扩展欧几里得算法
	中国剩余定理
	高斯消元
	组合计数
	容斥原理
	简单博弈论
动态规划
	背包问题
	线性DP
	区间DP
	计数类DP
	数位统计DP
	状态压缩DP
	树形DP
	记忆化搜索
贪心
时空复杂度分析
*/
```

[java.docx](./Java基础课后习题答案.docx)
[java.pdf](./Java基础课后习题答案.pdf)
```cpp
<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8" />
    <title>计专2301 宋祎梵</title>
    <style>
        #kuang_0 {
            background-color: #6b1f0f;
            width: 1000px;
        }

        #kuang_1 {
            background-color: #dfd0c9;
            height: 20px;
            text-align: center;
        }

        #topimg {
            padding-top: 10px;
            padding-bottom: 10px;
            background-color: #6b1f0f;
        }

        #banquan {
            background-image: url(./images/bg10.jpg);
            color: white;
            height: 60px;
            text-align: center;
            padding-top: 20px;
        }

        #kuang_left {
            float: left;
            width: 210px;
            background-color: #af7138;
            padding: 0px;
            height: 750px;
        }

        #kuang_right {
            float: right;
            width: 750px;
            background-color: #fef1ce;
            height: 750px;
        }

        #kuang_gywm {
            background-color: #af7138;
        }

        #kuang_4 {
            height: 800px;
        }

        #chanpingfenlei {
            width: 200px;
            height: 180px;
            border-radius: 50px;
            border: 2px solid red;
            text-align: center;
        }
    </style>
</head>

<body>
    <div id="kuang_0">
        <div id="kuang_1">
            网站首页|关于我们|最新动态|产品展示|茶文化|茶与健康|销售网络|招商加盟|留言板|人才招聘|友情链接
        </div>
        <div>
            <img src="./images/top.gif" id="topimg" usemap="#map">
            <map name="map">
                <area shape="rect" coords="347,47,420,160" href="./html/1.html">
            </map>
        </div>
        <dir id="kuang_left">
            <img src="./images/gywm.jpg">
            <br>
            百年字号——始创于民国零五年，世纪沧桑，几经风雨。公元一九九八年，后世传人秋香，秉承祖训担承起振兴之大任，八年的努力，无数的艰辛，今天已成为一个以优质茶叶、林木、水果种植加工、白酒饮料生产、石油化工产品营销及餐饮服务为一体的集团企业。公司注册资金118万元，员工196人…………
            <br>
            <br>
            <br>
            更多...
            <img src="./images/cpfl.jpg">
            <br>
            <img src="./images/bgdi.jpg">
            <div id="chanpingfenlei">
                推荐
                <br>
                1
                <br>
                <hr>
                2
                <br>
                <hr>
                3
                <br>
                <hr>
                4
                <br>
                <hr>
            </div>
        </dir>
        <dir id="kuang_right">
            <img src="./images/bg12.jpg">
            <br>
            <img src="./images/bg16.jpg"><img src="./images/bg17.jpg">
            <ul>
                <li>千年古树，百年古茶&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                </li>
                <li>111111111111111&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                </li>
                <li>111111111111111&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                </li>
                <li>111111111111111&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                </li>
                <li>111111111111111&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                </li>
                <li>111111111111111&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                </li>
                <li>111111111111111&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                </li>
                <li>111111111111111&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                </li>
            </ul>
            <br>
            <img src="./images/cwh.jpg"><img src="./images/bg17.jpg">
            <img src="./images/cyjk.jpg"><img src="./images/bg17.jpg">
            <table>
                <tr>
                    <td>
                        <ul>
                            <li>千年古树，百年古茶&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                            </li>
                            <li>111111111111111&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                            </li>
                            <li>111111111111111&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                            </li>
                            <li>111111111111111&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                            </li>
                            <li>111111111111111&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                            </li>
                        </ul>
                    </td>
                    <td>
                        <ul>
                            <li>千年古树，百年古茶&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                            </li>
                            <li>111111111111111&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                            </li>
                            <li>111111111111111&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                            </li>
                            <li>111111111111111&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                            </li>
                            <li>111111111111111&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;xxxx-xx-xx
                            </li>
                        </ul>
                    </td>
                </tr>
            </table>
        </dir>
        <div id="kuang_4"></div>
        <div id="banquan">茶叶有限公司&copy;计专2301 宋祎梵</div>
    </div>
</body>

</html>
```