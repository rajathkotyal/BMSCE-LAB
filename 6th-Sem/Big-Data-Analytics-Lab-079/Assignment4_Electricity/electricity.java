package electricity;

import java.io.IOException;
import java.util.StringTokenizer;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class electricity{

  public static class TMapper extends Mapper<Object, Text, Text, IntWritable>{


    public void map(Object key, Text value, Context context) throws IOException, InterruptedException {
      StringTokenizer itr = new StringTokenizer(value.toString());
      String year = itr.nextToken();
      Text word = new Text();
      String lasttoken = "" ;
      while (itr.hasMoreTokens()) {
        lasttoken = itr.nextToken();
        
      }
      word.set(year);
      int avgprice = Integer.parseInt(lasttoken);
      context.write(word, new IntWritable(avgprice));
    }
  }

  public static class IntReducer
       extends Reducer<Text,IntWritable,Text,IntWritable> {
    public void reduce(Text key, Iterable<IntWritable> values,
                       Context context
                       ) throws IOException, InterruptedException {
    	final IntWritable maxavg = new IntWritable(35);
      
   
        for (IntWritable val : values) {
             if (val.compareTo(maxavg)<0 ){
            	 context.write(key, new IntWritable(val.get()));
             }
           }
          
    }
  }

  public static void main(String[] args) throws Exception {

    
	    Configuration conf = new Configuration();
	    Job job = Job.getInstance(conf);
	    job.setJarByClass(electricity.class);
	    job.setMapperClass(TMapper.class);
	    job.setCombinerClass(IntReducer.class);
	    job.setReducerClass(IntReducer.class);
	    job.setOutputKeyClass(Text.class);
	    job.setOutputValueClass(IntWritable.class);
	    FileInputFormat.addInputPath(job, new Path(args[0]));
	    FileOutputFormat.setOutputPath(job, new Path(args[1]));
	    System.exit(job.waitForCompletion(true) ? 0 : 1);
  }
}