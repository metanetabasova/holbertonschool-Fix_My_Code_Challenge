# FizzBuzz Algorithm in Python

Bu layihə klassik **FizzBuzz** alqoritminin Python 3-də düzgün və optimallaşdırılmış həllini təqdim edir.

## 📌 Problem Haqqında
FizzBuzz məsələsində 1-dən `n`-ə qədər olan ədədlər üçün:
- **3-ə bölünən** ədədlərin əvəzinə `Fizz`
- **5-ə bölünən** ədədlərin əvəzinə `Buzz`
- **Həm 3-ə, həm də 5-ə bölünən (15-ə bölünən)** ədədlərin əvəzinə `FizzBuzz`
- Qalan ədədlərin isə olduğu kimi çap olunması tələb olunur.

---

## 🔍 Səhvin Təhlili (Bug Analysis)
Əvvəlki kodda `15` ədədi üçün `FizzBuzz` yerine `Fizz` çap olunurdu. 

**Nədən kaynaklanırdı?**
Python şərtləri (`if / elif`) yuxarıdan aşağıya doğru sırayla yoxlayır. Əgər `n % 3 == 0` şərti `n % 15 == 0` şərtindən **əvvəl** yazılarsa, 15 ədədi 3-ə bölündüyü üçün ilk şərt doğru sayılır və kod `FizzBuzz` şərtinə heç vaxt çatmadan "Fizz" çap edir.

---

## 🛠️ Düzgün Kod İmplementasiyası

```python
#!/usr/bin/python3
def fizzbuzz(n):
    for i in range(1, n + 1):
        # Həm 3, həm 5 (və ya 15-ə) bölünmə şərti ən başda olmalıdır
        if i % 3 == 0 and i % 5 == 0:
            print("FizzBuzz", end=" ")
        elif i % 3 == 0:
            print("Fizz", end=" ")
        elif i % 5 == 0:
            print("Buzz", end=" ")
        else:
            print(i, end=" ")

if __name__ == "__main__":
    fizzbuzz(50)
