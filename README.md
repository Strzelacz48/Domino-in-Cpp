# Domino-in-Cpp

![](https://i.imgur.com/ezqRHGU.png)

Domino to jedna z najstarszych - i zarazem najprostszych pod względem reguł - gier planszowych. To gra dla osób, które nie lubią gier karcianych, więc unikają obecnych również w grze pokera i blackjacka. Nie oznacza to jednak, że w domino brakuje głębi - uważny gracz rozpozna, jakie kostki mają inni zawodnicy i wykorzysta ten fakt przeciwko nim, blokując ich lub blefując.
![](https://i.imgur.com/A5UGD8U.png)

## Zasady gry

### Domino dobierane

Celem tego wariantu gry jest pozbycie się wszystkich kostek. Zawodnik, który wykona to zadanie jako pierwszy, wygrywa rundę.

![](https://i.imgur.com/Sa9Jz4q.png)



Z zestawu 28 unikalnych kostek każdy gracz losuje 7 z nich, a pozostałe wracają do puli. Kostki stawia się tak, aby oczka były niewidoczne dla pozostałych zawodników.

Rozgrywkę rozpoczyna osoba, która wylosowała największy dublet, czyli kostkę, która ma największą identyczną liczbę oczek po dwóch stronach. Gracz kładzie kostkę na stole, a pozostali dokładają swoje kostki tak, aby stykające się pola miały taką samą liczbę oczek. Tworzy to linię gry.

Często zdarza się, że zawodnik nie ma kostki, którą może dołożyć do układu na stole. W takim wypadku dobiera jedną kostkę z wolnej puli do czasu, aż znajdzie taką, którą może wykorzystać. Jeżeli pula się kończy, gracz pasuje.

W przypadku, gdy żaden z zawodników nie może dołożyć kostki, zabawę przerywa się, a wygrywa osoba z najniższą sumą oczek na posiadanych kostkach.

Zwycięzca rundy otrzymuje liczbę puntów równą sumie oczek na kostkach posiadanych przez przegranych zawodników. Grę wygrywa osoba, która jako pierwsza osiągnie wynik równy 60 punktom.

### Domino zwykłe

To najprostszy typ gry. Zasady są takie same, jak w opisanym powyżej domino dobieranym, jednak nie ma tutaj puli, z której zawodnicy dobierają kostki. Przez całą rozgrywkę można więc korzystać wyłącznie z tych, które wylosowaliśmy na początku.

### Domino trójkowe

W tym wariancie punkty zdobywa się na końcu każdej kolejki, po zsumowaniu oczek na otwartych końcach łańcucha domino. Jeżeli ta suma jest podzielna przez 3, gracz, który jako ostatni dołożył kostkę, zdobywa punkty równe wspomnianej sumie.

Domino trójkowe pozwala nawet blefować - gracz nie zawsze musi zagrywać najlepszą kostką, by zmylić innych zawodników i zostawić cenną liczbę oczek na później, kiedy przydadzą się bardziej. Nic nie stoi również na przeszkodzie, by sprytnym zagraniem zablokować innych uczestników zabawy.

Runda kończy się, gdy jedna z osób dołoży ostatnią kostkę lub gdy nikt nie może już wykonać ruchu. Gracz zdobywa punkty w liczbie równej sumie oczek na kostkach przeciwników, zaokrąglonej w górę lub w dół do najbliższej trójki. Aby wygrać zabawę, należy zdobyć 90 punktów.

### Domino piątkowe

Jak sugeruje nazwa, ten typ to wariant poprzedniej zabawy. W tym przypadku zawodnicy zdobywają punkty tylko, gdy wartość końcowa jest podzielna przez 5. Zdobyte na końcu rundy punkty zaokrąglamy do najbliższej piątki, w górę lub w dół. Końcowy wynik, potrzebny do zwycięstwa, wynosi z kolei 100.
## Plan
Planuję zaimplementować w terminalu grę w domino każdy tryb gry będzie własną klasą. Gra będzie przeznaczona dla 2 graczy i użytkownik będzie mógł wybrać tryb gry w poczatkowym menu. Gracz będzie mógł opuścić trwającą rozgrywkę i wrócić do menu. Jeśli gra się zakończy także nastąpi powrót do menu.
## Diagram klas

![](https://i.imgur.com/mn6BJCR.png)
