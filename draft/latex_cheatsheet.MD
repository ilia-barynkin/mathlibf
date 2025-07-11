## 📌 **Основы**

| Что                 | Синтаксис LaTeX                 | Пример                                |    |         |          |   |
| ------------------- | ------------------------------- | ------------------------------------- | -- | ------- | -------- | - |
| Инлайн формула      | `\( a^2 + b^2 = c^2 \)`         | $a^2 + b^2 = c^2$                     |    |         |          |   |
| Блочная формула     | `\[ a^2 + b^2 = c^2 \]`         | $a^2 + b^2 = c^2$                     |    |         |          |   |
| Степень             | `x^2`                           | $x^2$                                 |    |         |          |   |
| Индекс (нижний)     | `x_0`                           | $x_0$                                 |    |         |          |   |
| Греческие буквы     | `\varepsilon`, `\delta`, `\phi` | $\varepsilon, \delta, \phi$           |    |         |          |   |
| Дробь               | `\frac{a}{b}`                   | $\frac{a}{b}$                         |    |         |          |   |
| Корень              | `\sqrt{x}`, `\sqrt[n]{x}`       | $\sqrt{x}, \sqrt[3]{x}$               |    |         |          |   |
| Абсолютное значение | \`\left                         | x \right                              | \` | ( \left | x \right | ) |
| Скобки по размеру   | `\left( ... \right)`            | $\left( \frac{a}{b} \right)$          |    |         |          |   |
| Множество           | `\mathbb{R}`, `\in`, `\subset`  | $x \in \mathbb{R} \subset \mathbb{C}$ |    |         |          |   |

---

## 📌 **Кванторы и логика**

| Что          | Синтаксис LaTeX    | Пример                         |       |                      |             |                 |
| ------------ | ------------------ | ------------------------------ | ----- | -------------------- | ----------- | --------------- |
| Для всех     | `\forall`          | $\forall \varepsilon > 0$      |       |                      |             |                 |
| Существует   | `\exists`          | $\exists \delta > 0$           |       |                      |             |                 |
| Следует      | `\Rightarrow`      | (                              | x - a | < \delta \Rightarrow | f(x) - f(a) | < \varepsilon ) |
| Эквивалентно | `\Leftrightarrow`  | $A \Leftrightarrow B$          |       |                      |             |                 |
| Отрицание    | `\neg`             | $\neg P$                       |       |                      |             |                 |
| И/ИЛИ        | `\wedge`, `\vee`   | $P \wedge Q, \quad P \vee Q$   |       |                      |             |                 |
| Сокращения   | `\implies`, `\iff` | $A \implies B, \quad A \iff B$ |       |                      |             |                 |

---

## 📌 **Пределы, производные, непрерывность**

```latex
\[
\lim_{x \to a} f(x) = L
\quad
\Rightarrow
\quad
\forall \varepsilon > 0\ \exists \delta > 0:\ |x - a| < \delta \Rightarrow |f(x) - L| < \varepsilon
\]
```

```latex
\[
f \text{ непрерывна в } a
\iff
\lim_{x \to a} f(x) = f(a)
\]
```

```latex
\[
f'(x) = \lim_{h \to 0} \frac{f(x + h) - f(x)}{h}
\]
```

---

## 📌 **Функции, отображения, множества**

```latex
f : \mathbb{R} \to \mathbb{R}
\quad\text{или}\quad
f : A \subset \mathbb{R} \to \mathbb{R}
```

```latex
\begin{cases}
1, & x \geq 0 \\
0, & x < 0
\end{cases}
```

```latex
A = \{ x \in \mathbb{R} \mid x^2 < 2 \}
```

---

## 📌 **Разное**

| Что           | LaTeX                   | Пример                            |                   |         |          |                   |
| ------------- | ----------------------- | --------------------------------- | ----------------- | ------- | -------- | ----------------- |
| Интеграл      | `\int_a^b f(x)\, dx`    | $\int_0^1 x^2\, dx$               |                   |         |          |                   |
| Сумма         | `\sum_{n=1}^\infty a_n` | $\sum_{n=1}^\infty \frac{1}{n^2}$ |                   |         |          |                   |
| Произведение  | `\prod_{i=1}^n a_i`     | $\prod_{i=1}^n a_i$               |                   |         |          |                   |
| Модули, нормы | \`\left                 | \cdot \right                      | `, `\| \cdot \|\` | ( \left | x \right | , \quad \| x \| ) |
| Комментарии   | `% это комментарий`     | не отображаются                   |                   |         |          |                   |

---

## ✍ Пример полной записи (равномерная непрерывность)

```latex
\[
f \text{ равномерно непрерывна на } D
\iff
\forall \varepsilon > 0\ \exists \delta > 0\ \forall x, y \in D:\ |x - y| < \delta \Rightarrow |f(x) - f(y)| < \varepsilon
\]
```