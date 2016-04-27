Упражнение 10
===

Задачи
---

**Задача 1** Singleton

**Задача 2** Multiton

**Задача 3** SingletonFactory

**Задача 3** MultitonFactory


**Задача 10** Намерете начин да се изрази:
  sort(T * arr, int n, bool (comperator*)(T, T) = operator<(T, T))
Примери:

int a[10];
sort(a, 10, operator<(int, int));

Decimal d[10];
sort(d, 10, Decimal::operator<(Decimal))

bool someComperator(Decimal a ,Decimal b) ...

...
sort(d, 10, someComperator);


Reference
---
[Design Patterns|https://en.wikipedia.org/wiki/Design_pattern]
[Singleton|https://en.wikipedia.org/wiki/Singleton_pattern]
[Multiton|https://en.wikipedia.org/wiki/Multiton_pattern]
[Factory Method|https://en.wikipedia.org/wiki/Factory_method_pattern]
