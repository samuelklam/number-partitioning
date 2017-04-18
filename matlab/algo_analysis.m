clear all;
%% KK
fileID = fopen('kk_25k.txt', 'r');
formatSpec = '%d %f %d';
sizetimings = [3 100];
results = fscanf(fileID,formatSpec,sizetimings);

mean_residue_kk = mean(results(1,:));
mean_time_kk= mean(results(2,:));

%% Hill Climb
fileID = fopen('hill_climb_25k.txt', 'r');
formatSpec = '%d %f %d';
sizetimings = [3 100];
results = fscanf(fileID,formatSpec,sizetimings);

mean_residue_hill_climb = mean(results(1,:));
mean_time_hill_climb = mean(results(2,:));

%% Repeated Random
fileID = fopen('rep_rand_25k.txt', 'r');
formatSpec = '%d %f %d';
sizetimings = [3 100];
results = fscanf(fileID,formatSpec,sizetimings);

mean_residue_rep_rand = mean(results(1,:));
mean_time_rep_rand = mean(results(2,:));

%% Simulated Annealing
fileID = fopen('sim_anneal_25k.txt', 'r');
formatSpec = '%d %f %d';
sizetimings = [3 100];
results = fscanf(fileID,formatSpec,sizetimings);

mean_residue_sim_anneal= mean(results(1,:));
mean_time_sim_anneal= mean(results(2,:));

%% Hill-Climb Pre-Partitioning
fileID = fopen('pre_hill_climb_25k.txt', 'r');
formatSpec = '%d %f %d';
sizetimings = [3 100];
results = fscanf(fileID,formatSpec,sizetimings);

mean_residue_hill_climb_pre_part= mean(results(1,:));
mean_time_hill_climb_pre_part= mean(results(2,:));

%% Repeated Random Pre-Partitioning
fileID = fopen('pre_rep_rand_25k.txt', 'r');
formatSpec = '%d %f %d';
sizetimings = [3 100];
results = fscanf(fileID,formatSpec,sizetimings);

mean_residue_rep_rand_pre_part = mean(results(1,:));
mean_time_rep_rand_pre_part = mean(results(2,:));

%% Simulated Annealing Pre-Partitioning
fileID = fopen('pre_sim_anneal_25k.txt', 'r');
formatSpec = '%d %f %d';
sizetimings = [3 100];
results = fscanf(fileID,formatSpec,sizetimings);

mean_residue_sim_anneal_pre_part= mean(results(1,:));
mean_time_sim_anneal_pre_part= mean(results(2,:));

fprintf('Residue of No Partition Algorithms: \n')
fprintf('Hill Climbing: %.0f\n', mean_residue_hill_climb)
fprintf('Repeated Random: %.0f\n', mean_residue_rep_rand)
fprintf('Simulated Annealing: %.0f\n\n', mean_residue_sim_anneal)

fprintf('Residue of Partitioned Algorithms: \n')
fprintf('Hill Climbing Pre Partitioned: %.0f\n', mean_residue_hill_climb_pre_part)
fprintf('Simulated Annealing Pre Partitioned: %.0f\n', mean_residue_sim_anneal_pre_part)
fprintf('Repeated Random Pre Partitioned: %.0f\n', mean_residue_rep_rand_pre_part)

all_mean_residues = [log10(mean_residue_hill_climb), log10(mean_residue_rep_rand), log10(mean_residue_sim_anneal), log10(mean_residue_hill_climb_pre_part), log10(mean_residue_sim_anneal_pre_part),log10(mean_residue_rep_rand_pre_part)];
b = bar(all_mean_residues);
set(gca, 'XTickLabel', {'hill climb', 'repeated random', 'sim anneal','hill climb pre part', 'sim anneal pre part','rep rand pre part'});

%% Plot timings for each algorithm