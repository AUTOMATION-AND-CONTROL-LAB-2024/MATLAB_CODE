function saveAcqData(data_array, colNames, filename)
    % Creare una tabella con i dati e i nomi delle variabili specificati
    data = array2table(data_array, 'VariableNames', colNames);
    raw_directory = 'RAW_DATA/';
    raw_filename = raw_directory + filename;
    % Salvare la tabella in un file specificato
    save(raw_filename, "data");
end