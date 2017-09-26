#!/bin/bash

#SBATCH --job-name=CudaMulti
#SBATCH --output=resultado
#SBATCH --ntasks=10
#SBATCH --nodes=4
#SBATCH --gres=gpu:1

export PATH=/usr/local/cuda-8.0/bin${PATH:+:${PATH}}
export LD_LIBRARY_PATH=/usr/local/cuda-8.0/lib64/${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}

export CUDA_VISIBLE_DEVICES=1

./mul
