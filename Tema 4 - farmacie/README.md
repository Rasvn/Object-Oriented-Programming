# Farmacie

Creați o aplicație care permite:
- gestiunea unei liste de medicamente. Medicament: denumire, preț, producător, substanța activa
- adăugare, ștergere, modificare și afișare medicamente
- căutare medicament
- filtrare medicamente după: preț, substanța activa
- sortare medicamente după: denumire, producător, substanța activa + preț

Cerințe generale:
- Creați o aplicație C++, folosiți paradigma orientat obiect
- Aplicația are interfața utilizator tip consola
- Utilizați procesul de dezvoltare bazat pe funcționalități (Feature driven development). Identificați funcționalitățile și planificați-le pe doua iterații
- Folosiți o arhitectură stratificata (UI / Services(GRASP Controller) / Repository).
- Creați clase pentru: Domain, Service, UI, Repository.
- Toate funcțiile necesare vor fi specificate și testate. (Test Code Coverage >99% la toate modulele in afara de UI)
- Fara warninguri (in Visual Studio warning level /W4, treat warning as errors)
- Const Correctness: folosiți calificativul const pentru variabile/parametrii care nu sunt modificații, folosiți calificativul const pentru metode care nu modifica starea obiectelor, transmiteți parametrii prin const & peste tot unde este posibil, evitați copierea obiectelor când nu este necesar.

Timp de lucru 2 săptămâni