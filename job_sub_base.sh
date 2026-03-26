#!/bin/bash
# ------------ LSF directives ------------
#BSUB -q man
#BSUB -J test_base[1-1]%1
#BSUB -n 8
#BSUB -R "span[hosts=1] rusage[mem=10GB]"
#BSUB -W 72:00
#BSUB -u frefri@dtu.dk
#BSUB -N

##BSUB -o /zhome/62/e/209625/BalOpt_Fork_Github/joblogs/%I.out
##BSUB -e /zhome/62/e/209625/BalOpt_Fork_Github/joblogs/%I.err
# ----------------------------------------

# Load GAMS 47
export PATH=/appl/gams/47.6.0:$PATH
export LD_LIBRARY_PATH=/appl/gams/47.6.0:$LD_LIBRARY_PATH

# Define scenario list
SCENARIOS=(
  base
)

# Check if LSB_JOBINDEX is set
if [ -z "$LSB_JOBINDEX" ]; then
  echo "Error: LSB_JOBINDEX is not set." >&2
  exit 1
fi

# Resolve scenario
SCEN=${SCENARIOS[$((LSB_JOBINDEX - 1))]}

# Confirm resolved scenario
echo "Running job index: $LSB_JOBINDEX"
echo "Scenario resolved to: $SCEN"

# Move to model directory

cd /work3/frefri/balmorel-gsa/Balmorel/${SCEN}/model || {
  echo "Failed to cd into scenario directory: ${SCEN}" >&2
  exit 2
}

# Run GAMS with thread count from LSF
gams Balmorel --threads=$LSB_DJOB_NUMPROC