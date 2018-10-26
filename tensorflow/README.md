# This directory contains the python scripts and models for creating a Trained Graph which is used to identify objects within different object classes.

### Some notes about getting this to work properly:

1. Make sure you are on Python version 3.6
 * Python 3.7 will NOT work - last tested using Python 3.6.6
2. Having completed Step 1, you should now be able to do `pip install tensorflow`
3. Set the following environment variables:
 * IMAGE_SIZE=128 (or whatever image size will be used)
 * ARCHITECTURE="mobilenet_0.50_${IMAGE_SIZE}" (compression factor of 0.5)
4. Start training:
 `sudo python3 -m scripts.retrain   --bottleneck_dir=tf_files/bottlenecks   --model_dir=tf_files/models/   --summaries_dir=tf_files/training_summaries/"${ARCHITECTURE}"   --output_graph=tf_files/retrained_graph.pb   --output_labels=tf_files/retrained_labels.txt   --architecture="${ARCHITECTURE}"   --image_dir=tf_files/parking_spots`

 * This will create a Trained Graph for the flower photos in the flower_photos directory as demonstrated in 
 https://codelabs.developers.google.com/codelabs/tensorflow-for-poets/#0

5. Once the Trained Graph is finished, run the following command to use the Trained Graph to identify an image
 `sudo python3 -m scripts.label_image --input_width=${IMAGE_SIZE} --input_height=${IMAGE_SIZE}     --graph=tf_files/retrained_graph.pb      --image=tf_files/flower_photos/daisy/21652746_cc379e0eea_m.jpg`

 * The `--image` flag should point to the target image to be analyzed, and the `--graph` flag should point to the Trained Graph created in Step 4.
 * Also note that the `retrained_labels.txt` refers to the object classes the graph is trained to identify, which is built off of the names of the directories within `flower_photos`
