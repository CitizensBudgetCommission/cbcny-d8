<div id="block-<?php echo $block->module .'-'. $block->delta; ?>" class="block <?php echo $block_classes; ?>">
<div class="Block">
	    <div class="Block-tl"></div>
	    <div class="Block-tr"><div></div></div>
	    <div class="Block-bl"><div></div></div>
	    <div class="Block-br"><div></div></div>
	    <div class="Block-tc"><div></div></div>
	    <div class="Block-bc"><div></div></div>
	    <div class="Block-cl"><div></div></div>
	    <div class="Block-cr"><div></div></div>
	    <div class="Block-cc"></div>
	    <div class="Block-body">
	
		<?php if ($block->subject): ?>
<div class="BlockHeader">
			    <div class="header-tag-icon">
			        <div class="BlockHeader-text">
				
				<?php echo $block->subject; ?>

			        </div>
			    </div>
			    <div class="l"></div>
			    <div class="r"><div></div></div>
			</div>
			    
		<?php endif; ?>		
<div class="BlockContent">
		    <div class="BlockContent-body">
		  
			<?php echo $block->content; ?>

		    </div>
		</div>
		
		<?php echo $edit_links; ?>

	    </div>
	</div>
	
</div>
