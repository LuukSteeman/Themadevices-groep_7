## Vraag 1
Wat zijn de verschillen binnen de 22xx serie

> Hoeveel bandbreedte de osciloscoop tot zich beschikbaar heeft

## Vraag 2
Wat is de bandbreedte van de Picoscoop 2205

> 2204: 10Mhz
> 
> 2205: 25Mhz

Wat is de meerprijs van de 2205 ten opzichte van de 2204?

> 80 Euro dus 1.5x zo duur voor 2.5x zo veel bandbreedte

## Vraag 3
Wat is de maximale IngangsSpanning?

> 20 Volt

## Vraag 4
Waarom is het heel handig als je twee ingangskaalen hebt om te kunnen meten?

> Zodat je twee signalen kan vergelijken met elkaar. Om de ingangsignalen te checken. Om een referentie signaal te creeeren.


## Vraag 5
Met hoeveel samples per seconde digitaliseert de 2204 het signaal?

> 10Ms/s: 10.000.000 samples per seconde


## Vraag 6
Het is ook mogelijk een weergave op te slaan. Op deze manier kan je later de resultaten bekijken van je meting. Met het programma PicoScope is het dus ook mogelijk metingen later terug te kijken en te analyseren zonder dat je de scoop zelf nog nodig hebt. Zoek op wat voor "metingen" je kan verrichten op een signaal en wat deze betekenen. Kies drie mogelijkheden en beschrijf deze.

> 1: **Frequentie:**	Bij deze meting wordt de frequentie van het signaal gemeten.
> 
> 2: **DC Gemiddlede:** Bij deze meting wordt het gemiddelde voltage van het                        signaal gemeten.
> 
> 3: **Maximum:** 		Hierbij wordt de maximale spanning van een golf (de bovenkant van de wave) gemeten.

## Vraag 7
Kijk goed naar de instellingen van de oscilloscoop. Links op de Y-as staat de signaalsterkte in Volt. Op de
horizontale as, de X-as staat de tijd in microseconden. Bespreek met elkaar hoe je de amplitude en
frequentie van deze blokgolf berekent. Wat is de (uitgerekende) frequentie van het signaal?

>**Sterkte van het signaal in Volt:**	2Volt
>
>**Tijd die een periode duurt:**		100 microSeconden
>
>**Berekende Frequentie:**				1/.0001 = 10000Hz = 10kHz

## Vraag 8
Onderzoek de instellingen. Welke type golfvormen kan je genereren vanuit de signaalgenerator?

>Arbitrary
>
>Sinus
>
>Vierkant
>
>Driehoek
>
>Schans omhoog
>
>Schans naar beneden
>
>Sin (X)/X
>
>Gaussi curve
>
>Halve Sinus
>
>DC Spanning


In de keuze voor het type signaal is er ook het type “arbitrary” zoek uit wat je hiermee kan doen en geef
dit aan in het volgende tekstvak:

>Bouw je eigen golf; Hiermee kan je je eigen golf ontwerpen en laten genereren door de signal generator.


## Vraag 9
Zoek uit welke vormen van triggeren je kan doen met de scoop en beschrijf het verschil tussen de vier
verschillende soorten is (zie hiervoor de helpfunctie):

>**Automatisch:**	Selecteert automatisch het trigger punt en laat de 						meting doorlopen
>`
>**Herhaal:**		Selecteer zelf het trigger punt en laat hem doorlopen
>
>**Enkel:**		  Selecteer automatisch het trigger punt en meet een 						keer zodra deze berijkt wordt
>
>**ETS:**		Gemiddelde van een aantal samples samen


## Vraag 10
Zoek in de helpfile op wat deze mode doet en bedenk waarvoor een Persistence Mode gebruikt zou
kunnen worden. Vul dat in het volgende vak in:

>Om fouten die weinig voorkomen te kunnen detecteren


## Vraag 11
Voor welke veldbus is het protocol al aanwezig? 

>Veldbus A

## Vraag 12
Nu je een idee hebt hoe de scope werkt zou je een aantal toepassingen kunnen bedenken voor het
gebruik van de scoop. Bedenk een 3 aantal toepassingen die je de komende jaren in je studie zou kunnen
gebruiken:

>Piekspanningen meten zodat de arduino niet opgeblazen wordt
>
>Analyse van geluidsignalen
>
>Debuggen van seriele communicatie tussen chips




# Deel 2

## Vraag 1
Zijn alle onderdelen aanwezig

> Nee, we misten een voeding. Hiervoor hebben we een vervangende gekregen. Dit is een andere dan bij het practicum hoort. Specificaties [hier](http://www.produktinfo.conrad.com/datenblaetter/500000-524999/510818-an-01-ml-DEHNER_SYS1421_NETZT_FESTS_5V_6W_de_en.pdf)

## Vraag 2
Welke eigenschap voor een voeding kun je zelf nog bedenken?

> De juiste connector bij de gegeven toepassing (micro usb, barrel connector)

## Vraag 3
De eigenschap van een “ideale” spanningsbron is het leveren van de juiste spanning bij iedere
willekeurige belasting. Bij iedere belasting levert de voeding exact de juiste (bijbehorende) stroom. De
spanning is dus vast en de stroom wordt door de voeding automatisch ingesteld. Bij grote (of zware)
belasting levert de voeding ook een grote stroom. Een spanningsbron mag niet worden kortgesloten, dan
gaat er (theoretisch) een oneindig grote stroom lopen. Hoe komt dat? Tip, verklaar dit aan de hand van de
wet van Ohm.

> Wet van Ohm: U = I * R. Omdat U constant is en R 0 benadert moet I oneindig benaderen om hieraan te voldoen.

## Vraag 4
Geef het antwoord van top tot top (Vtt) in millivolt. Dat is dus de spanning boven de nullijn plus de
spanning onder de nullijn (schat de waarde als het beeld niet goed stil staat):

> 381.5 mV
> Screenshot: Vraag_4_1.jpg

![Vraag_4_1.jpg]( https://raw.githubusercontent.com/LuukSteeman/Themadevices-groep_7/master/Opdracht%20Osciloscoop/Vraag_4_1.jpg "Screenshot 4")

Kijk in de specificatie van de voeding (staat op Sharepoint). Welke informatie is er gegeven over de
grootte van de rimpel? Reken de grootte om naar mV:

>Volgens de specificatie 150mV peak to peak ripple

## Vraag 5
Open je camera van je mobiel en schijn met de handzender in de camera. Welke kleur is het licht van de
IR-LED als je deze met de camera bekijkt?

> Het licht is paarsachtig

## Vraag 6
Wat is de frequentie van de zender?

> 36 KHz
> Screenshot: Vraag_6_1.jpg

![Vraag_6_1.jpg]( https://raw.githubusercontent.com/LuukSteeman/Themadevices-groep_7/master/Opdracht%20Osciloscoop/Vraag_6_1.jpg "Screenshot 6")


## Vraag 7
Bereken uit het plaatje serieel.jpg de bitsnelheid (probeer voor de bitsnelheid het aantal bits te delen op
de tijd). Bepaal daarna het betreffende karakter aan de hand van de bits via de ASCII-tabel. LET OP: na het
startbit komen EERST de minst significante bits (die je RECHTop schrijft). Een “laag signaal” is een ”1”

> Bitsnelheid: 2000 bits/s
> Het karakter is: 5

## Vraag 8
Wat is de spanning van het hoge - en het lage signaal?

> U-hoog = +6,5V
> U-laag = -6.3V

## Vraag 9

Hoe ziet de meting van de letter w eruit?

> Screenshot: Vraag_9_1.png

![Vraag_9_1.jpg]( https://raw.githubusercontent.com/LuukSteeman/Themadevices-groep_7/master/Opdracht%20Osciloscoop/Vraag_9_1.png "Screenshot 4")


## Vraag 10

> 3.5Khz
> Screenshot: Vraag_10_1.jpg

![Vraag_10_1.jpg]( https://raw.githubusercontent.com/LuukSteeman/Themadevices-groep_7/master/Opdracht%20Osciloscoop/Vraag_10_1.jpg "Screenshot 4")
