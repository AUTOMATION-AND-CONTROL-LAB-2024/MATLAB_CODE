function plotData(tableData, labels, directory)

    % Create the directory if it doesn't exist
    if ~exist(directory)
        mkdir(directory);
    end

    % Check if input is a table
    if ~istable(tableData)
        error('Input must be a table.');
    end
    
    % Extract the first column (x-axis values)
    time = tableData{:, 1};
    
    % Determine number of columns in the table
    numCols = size(tableData, 2);
    
    % Plot each column against the first column
    % Add labels and legend
    
    
    for col = 2:numCols
        H = figure('visible', 'off');
        grid on;
         hold on;
        signal_name = labels(col);
        plot(time, tableData{:, col}, 'DisplayName', ['Column ' num2str(col-1)]);
        xlabel('Time');
        ylabel(signal_name);
        title(signal_name);
        % Save the plot as PNG in the custom directory
        fullPath = directory+'/'+signal_name+'.png';
        saveas(gcf,fullPath)
    end
    hold off
end
