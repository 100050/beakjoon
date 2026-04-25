# [Silver II] Triples - 10357 

[문제 링크](https://www.acmicpc.net/problem/10357) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 브루트포스 알고리즘, 정수론

### 제출 일자

2026년 04월 26일 01:17:10

### 문제 설명

<p>Mr. A invites you to solve the following problem:</p>

<p>“Let be \(m\) and \(n\) two positive integers, \(5 \le m \le 100\), \(2 \le n \le 100\). Consider the following sets of triples:</p>

<p>\[T_{m,j} = \left\{ { (x,y,z) \in \mathbb{N}^{3} }|{ x \le y \le z \le m ~ and ~ x^j + y^j = z^j } \right\} ,  j = 2 .. n\]</p>

<p>where \(\mathbb{N}\) is the set of nonnegative integers (\(\mathbb{N}\) = {0, 1, 2, ...}).</p>

<p>The problem asks you to compute the sum \(S_{m,n}\):</p>

<p>\[S_{m,n} = \sum_{j=2}^{n}{card(T_{m,j})}\]</p>

<p>where \(card(T_{m,j})\) is the number of elements of the set \(T_{m,j}\)."</p>

### 입력 

 <p>The input file contains a single test. The first line of the input file contains the value of \(m\)and the second line contains the value of \(n\).</p>

<p> </p>

### 출력 

 <p>The result will be written to standard output.</p>

