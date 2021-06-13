package temperature;

import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;
import java.io.IOException;

public class AverageMapper extends Mapper <LongWritable, Text, Text, IntWritable>
{
public static final int MISSING = 9999;

public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException
{
	String line = value.toString();
	String year = line.substring(15,19);
	int temperature;
	if (line.charAt(87)=='+')
			temperature = Integer.parseInt(line.substring(88, 92));
	else
		temperature = Integer.parseInt(line.substring(87, 92));
	String quality = line.substring(92, 93);
	if(temperature != MISSING && quality.matches("[01459]"))
		context.write(new Text(year),new IntWritable(temperature));
	}
}