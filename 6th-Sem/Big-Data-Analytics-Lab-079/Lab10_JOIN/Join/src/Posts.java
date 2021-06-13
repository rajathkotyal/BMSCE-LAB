import java.io.IOException;

import org.apache.hadoop.io.*;
import org.apache.hadoop.mapred.*;

public class Posts extends MapReduceBase implements Mapper<LongWritable, Text, TextPair, Text>  {

	@Override
	public void map(LongWritable key, Text value, OutputCollector<TextPair, Text> output, Reporter reporter)
      			throws IOException 
	{
		String valueString = value.toString();
		String[] SingleNodeData = valueString.split("\t");
		output.collect(new TextPair(SingleNodeData[3], "0"), new Text(SingleNodeData[9]));
	}
}