# [Gold III] 제곱잉여 - 7558 

[문제 링크](https://www.acmicpc.net/problem/7558) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 정수론, 페르마의 소정리

### 제출 일자

2026년 04월 26일 01:17:09

### 문제 설명

<p>1801년에 칼 프리드리히 가우스 (1777-1855)는 현대 정수론의 토대를 마련한 "Disquisitiones Arithmeticae"를 발표했고, 오늘날까지 팔리고 있다. 이 책에서 가장 많이 나온 주제 중 하나는 제곱잉여이다.</p>

<p>소수 \(p\)와 정수 \(a \not\equiv 0 \pmod{p}\) 가 있다. \(a\)가 \(p\)에 대한 제곱잉여가 되려면 다음과 같은 조건을 만족하는 정수 \(x\)가 존재해야 한다.</p>

<p>\[x^2 \equiv a \pmod{p}\]</p>

<p>라그랑주 (1752-1833)은 아래와 같은 르장드르 기호를 만들었다.</p>

<p>\[\left(\frac{a}{p}\right) = <br>
\begin{cases}<br>
 1 & a \text{ 가 } p \text{ 에 대한 제곱잉여인 경우} \\<br>
-1 & a \text{ 가 } p \text{ 에 대한 제곱잉여가 아닌 경우} \\<br>
\end{cases}\]</p>

<p>르장드르 기호를 계산하려면 다음과 같은 성질을 이용하면 좋으며, 서로 다른 홀수 소수 \(p\), \(q\)와 \(p\)로 나누어 떨어지지 않는 \(a\), \(b\)에 대해서만 성립한다.</p>

<ol>
	<li>\(\left(\frac{ab}{p}\right) = \left(\frac{a}{p}\right)\left(\frac{b}{p}\right)\)</li>
	<li>\(\left(\frac{1}{p}\right) = 1\)</li>
	<li>\(a \equiv b \pmod{p} \Rightarrow \left(\frac{a}{p}\right) = \left(\frac{b}{p}\right)\)</li>
	<li>\(\left(\frac{-1}{p}\right) = (-1)^{(p-1)/2}, \left(\frac{2}{p}\right) = (-1)^{(p^2-1)/8}\)</li>
	<li>\(\left(\frac{p}{q}\right)\left(\frac{q}{p}\right) = (-1)^{(p-1)(q-1)/4}\)</li>
</ol>

<p>이제 다음과 같이 르장드르 기호를 쉽게 계산할 수 있다.</p>

<p>\[\left(\frac{29}{79}\right) = (-1)^{78\cdot28/4} \left(\frac{79}{29}\right)  = \left(\frac{79}{29}\right) = \left(\frac{-8}{29}\right) = \left(\frac{-1}{29}\right) \left(\frac{2}{29}\right)^{3} = \left(\frac{-1}{29}\right) \left(\frac{2}{29}\right) \\ = (-1)^{28/2}(-1)^{(29^2-1)/8} = (-1)^{14}(-1)^{105} = -1\]</p>

### 입력 

 <p>입력은 여러 개의 테스트 케이스로 이루어져 있고,각 테스트 케이스는 두 정수 \(a\)와 \(p\)로 이루어져 있다. \(p\) (\(2 < p < 10^9\))는 홀수 소수이고, \(a\)는 \(a \not\equiv 0 \pmod{p}\)와 \(\left| a \right| \le 10^9\)를 만족한다.</p>

### 출력 

 <p>각 테스트 케이스마다 "Scenario #i:"를 출력한다. i는 테스트 케이스 번호이며 1부터 시작한다. 그 다음 줄에 \(\left(\frac{a}{p}\right)\)를 출력하고 빈 줄을 하나 출력한다.</p>

