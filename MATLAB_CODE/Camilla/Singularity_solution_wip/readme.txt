idea: 
il gimbal block avviene per pitch +-pi/2
recommended range = [-80;+80]°
dato dalla euler representation
fonti: quaternions representation dovrebbe evitare la singolarità
(non ben chiaro se altri drawback oltre a complessità di rappresentazione e non ben chiaro se rischio di incorrere in altre singolarità <-- devo ritornare su questo e controllare)
blocco quadcopter contenente rappresentazione modello: quaternioni (esiste blocco px4 che ti dà la misura del quaternione in ouput)
conversione tramite matrice in roll pitch yaw che è ciò che ci interessa

potrebbe andare bene anche l'imposizione di limiti sugli euler angles, ho letto che va bene in assenza di disturbi tipici del volo, che è poi il nostro caso
problema: non riesco a trovare fonti su come imporli in maniera effciente: direttamente nel modello o col controllo?