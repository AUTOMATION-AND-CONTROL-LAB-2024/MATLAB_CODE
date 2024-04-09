function zeroIndices = findZeroIndices(array)
    % Inizializza un vettore vuoto per gli indici
    zeroIndices = [];
    
    % Scorre attraverso l'array
    for i = 1:numel(array)
        % Controlla se il valore corrente è zero
        if array(i) <= 0.01
            % Aggiunge l'indice corrente al vettore degli indici
            zeroIndices = [zeroIndices, i];
        end
    end
end