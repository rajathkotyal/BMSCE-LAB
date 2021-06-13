import java.io.IOException;
import java.util.Iterator;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FSDataInputStream;
import org.apache.hadoop.fs.FSDataOutputStream;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapred.*;

import org.apache.hadoop.io.IntWritable;

public class User extends MapReduceBase implements Mapper<LongWritable, Text, TextPair, Text> {

	@Override
	public void map(LongWritable key, Text value, OutputCollector<TextPair, Text> output, Reporter reporter) 
			throws IOException 
	{	
	
		String valueString = value.toString();
		String[] SingleNodeData = valueString.split("\t");
		output.collect(new TextPair(SingleNodeData[0], "1"), new Text(SingleNodeData[1]));
	}
}

