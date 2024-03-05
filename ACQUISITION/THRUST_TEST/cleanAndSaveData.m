function cleanAndSaveData(filename, colNames, window_size)
    % Load raw data
    raw_data = load(filename);
    raw_data = raw_data.data;
    dataset = table2array(raw_data);
    %% dataset = table2array(dataset);
    % Find the indices of the first and last non-zero values
    nonzero_indices = find(dataset(:, 2) ~= 0);
    first_idx = nonzero_indices(1);
    last_idx = nonzero_indices(end);
    
    % Extract the effective dataset
    effective_dataset = dataset(first_idx:last_idx, :);
    
    % Compute time offset and adjust timestamps
    time_offset = effective_dataset(1, 1);
    effective_dataset(:, 1) = effective_dataset(:, 1) - time_offset;
    
    % Apply moving average filtering
    filtered_data = zeros(size(effective_dataset));
    for i = 1:size(effective_dataset, 2)
       filtered_data(:, i) = movmean(effective_dataset(:, i), window_size);
    end
        
    % Replace the time column with the adjusted timestamps
    filtered_data(:, 1) = effective_dataset(:, 1);
    
    % Convert filtered data to a table
    filtered_data_table = array2table(filtered_data, 'VariableNames', colNames);
    
    % Create output filename
    filename = erase(filename, "RAW_DATA/");
    filename = "CLEAN_DATA/" + filename;
    
    % Save the cleaned data
    save(filename, "filtered_data_table");
end
