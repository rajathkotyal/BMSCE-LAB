package temperature;

import org.apache.hadoop.io.*;
import org.apache.hadoop.fs.*;
import org.apache.hadoop.mapreduce.*;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class AverageDriver
{
	public static void main (String[] args) throws Exception
	{
		if (args.length != 2)
		{
			System.err.println("Please Enter the input and output parameters");
			System.exit(-1);
		}
		Job job = new Job();
		job.setJarByClass(AverageDriver.class);
		job.setJobName("Max temperature");
		FileInputFormat.addInputPath(job,new Path(args[0]));
		FileOutputFormat.setOutputPath(job,new Path (args[1]));

		job.setMapperClass(AverageMapper.class);
		job.setReducerClass(AverageReducer.class);
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(IntWritable.class);
		System.exit(job.waitForCompletion(true)?0:1);
	}
}
