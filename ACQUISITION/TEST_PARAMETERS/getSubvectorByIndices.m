function subvector = getSubvectorByIndices(vector, indices)
    % Inizializza un vettore vuoto per il sottovettore
    subvector = [];
    
    % Scorre attraverso gli indici specificati
    for i = 1:length(indices)
        % Verifica che l'indice sia valido
        if indices(i) >= 1 && indices(i) <= length(vector)
            % Aggiunge l'elemento corrispondente all'indice al sottovettore
            subvector = [subvector, vector(indices(i))];
        end
    end
end